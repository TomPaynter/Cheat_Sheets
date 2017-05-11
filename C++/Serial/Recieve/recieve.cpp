#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "boost/circular_buffer.hpp"
#include "boost/asio.hpp"
#include "SpektrumProtobuf.pb.h"
#include <iomanip>
#include "serial/serial.h"
#include "Calibrate.hpp"

using namespace std;
using namespace boost::asio;

int main(int argc, char **argv) {

  uint8_t verbose = 0, calibrate = 0, run = 0;
  SpektrumCalibrate_c SpektrumCalibrate;

  for(int i = 0; i < argc; i++) {
    string arguement = argv[i];

    if (arguement == "-v")
      verbose = 1;

    if (arguement == "-c")
      calibrate = 1;
  }

  if (calibrate == 0)
      SpektrumCalibrate.import_calibration();

  serial::Serial my_serial(argv[1], 115200, serial::Timeout::simpleTimeout(24));

  boost::circular_buffer<uint8_t> inpacket(32);
  for(int i=0; i < 32; i++)
    inpacket.push_back(0);

  uint16_t raw_spektrum[9];
  uint16_t calibrated_spektrum[9];

  while(1){
    uint8_t inbyte;
    my_serial.read(&inbyte, 1);

    inpacket.push_back(inbyte);

    if (  inpacket[0] == 0 &&
          inpacket[1] == 0 &&
          inpacket[31] == 255 &&
          inpacket[30] == 255 &&
          inpacket[29] == 255 &&
          inpacket[28] == 255 &&
          inpacket[27] == 255 &&
          inpacket[26] == 255 &&
          inpacket[25] == 255 &&
          inpacket[24] == 255 &&
          inpacket[23] == 255 &&
          inpacket[22] == 255 ) {

      uint16_t spektrum_rssi;

      spektrum_rssi = (inpacket[0]*256 + inpacket[1]);
      raw_spektrum[0] = (inpacket[2]*256 + inpacket[3]);
      raw_spektrum[1] = (inpacket[4]*256 + inpacket[5]);
      raw_spektrum[2] = (inpacket[6]*256 + inpacket[7]);
      raw_spektrum[3] = (inpacket[8]*256 + inpacket[9]);
      raw_spektrum[4] = (inpacket[10]*256 + inpacket[11]);
      raw_spektrum[5] = (inpacket[12]*256 + inpacket[13]);
      raw_spektrum[6] = (inpacket[14]*256 + inpacket[14]);
      raw_spektrum[7] = (inpacket[18]*256 + inpacket[19]);
      raw_spektrum[8] = (inpacket[20]*256 + inpacket[21]);

      if(calibrate) {
        for(int i =0; i<9; i++)
            cout << (raw_spektrum[i])<< " ";

        cout << "  -- RAW" << endl;
      }

      if (calibrate && run > 150) {
        SpektrumCalibrate.average(raw_spektrum);
      }
      else if (calibrate) {
        cout << "Centre Sticks NOW" << endl;
        run = (run + 1) % 200;
      }

      SpektrumCalibrate.calibrate(calibrated_spektrum, raw_spektrum);

      if(calibrate) {
        for(int i =0; i<9; i++)
            cout << (calibrated_spektrum[i])<< " ";

        cout << "  -- CALIBRATED" << endl;
      }

      Spektrum::SpektrumData packet_spektrum;

      packet_spektrum.set_rssi(spektrum_rssi);

      for(int i =0; i<8; i++){
        if(verbose) {
          cout << (calibrated_spektrum[i])<< " ";
        }
        packet_spektrum.add_data(calibrated_spektrum[i]);
      }

      if(verbose) {
        cout << endl;
      }

      if(calibrate) {
        cout << endl << endl << endl;
      }

        if (calibrate == 0) {
        string serialised_spectrum_packet = packet_spektrum.SerializeAsString();

        io_service io_service;
        ip::udp::socket socket(io_service);
        ip::udp::endpoint remote_endpoint;

        socket.open(ip::udp::v4());

        remote_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), 9000);

        boost::system::error_code err;
        socket.send_to(buffer(serialised_spectrum_packet, serialised_spectrum_packet.size()), remote_endpoint, 0, err);

        socket.close();
        }
      }
    }
  }

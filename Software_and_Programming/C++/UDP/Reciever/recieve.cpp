#include <iostream>
#include "boost/asio.hpp"
#include <iostream>


using namespace std;

int main(int argc, char **argv) {


  boost::asio::io_service io_service;
  boost::asio::ip::udp::socket socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 9000));

  while(1)
  {
    boost::array<char, 10> recv_buf;
    boost::asio::ip::udp::endpoint remote_endpoint;
    boost::system::error_code error;

    socket.receive_from(boost::asio::buffer(recv_buf),
        remote_endpoint, 0, error);

    string bob = recv_buf.data();
    cout << bob << endl;
  }
}

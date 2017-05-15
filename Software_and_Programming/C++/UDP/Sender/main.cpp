//As taken from http://stackoverflow.com/questions/24559909/sending-string-over-udp-in-c

//Also Helpful! http://stackoverflow.com/questions/33281753/unsafe-use-of-relative-rpath-libboost-dylib-when-making-boost-python-helloword-d

// I think i buggered up my boost install: install_name_tool -change libboost_system.dylib /Users/Emmet/Downloads/boost_1_63_0/stage/lib/libboost_system.dylib ./UDP_Server_Test

// Localhost is 127.0.0.1 !
#include "boost/asio.hpp"
using namespace boost::asio;

int main(){
  while(1) {
    io_service io_service;
    ip::udp::socket socket(io_service);
    ip::udp::endpoint remote_endpoint;

    socket.open(ip::udp::v4());

    remote_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), 9000);

    boost::system::error_code err;
    socket.send_to(buffer("Jane Doe", 8), remote_endpoint, 0, err);

    socket.close();
    }
  return 0;
}

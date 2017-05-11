#include "boost/asio.hpp"
#include <iostream>

using boost::asio::ip::udp;

int main(void) {

boost::asio::io_service io_service;

udp::socket socket(io_service, udp::endpoint(udp::v4(), 9000));

for (;;)
{
  boost::array<char, 10> recv_buf;
  udp::endpoint remote_endpoint;
  boost::system::error_code error;

  socket.receive_from(boost::asio::buffer(recv_buf),
      remote_endpoint, 0, error);

  std::string bob = recv_buf.data();
  std::cout << bob << std::endl;
}
}

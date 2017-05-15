#include <iostream>
#include <string>
#include <iomanip>
#include <stdint.h>
#include "can.pb.h"

int main(int argc, char *argv[])
{
    uint32_t data[] = {1, 0, 3, 0, 5, 6, 7, 0};

    can::CanPacket packet;
    packet.set_id(42);

    for (auto elem : data) {
        packet.add_data(elem);
    }

    std::cout << "ID: " << packet.id() << std::endl;
    std::cout << "data: " << packet.data_size() << " bytes" << std::endl;

    std::cout << std::endl;

    auto got = packet.data();
    for (int i = 0; i < packet.data_size(); ++i) {
        std::cout << "data[" << i << "]: " << got[i] << std::endl;
    }

    return 0;
}

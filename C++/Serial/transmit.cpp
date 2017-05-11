#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "../serial/serial.h"

using namespace std;

int main(int argc, char **argv) {

  serial::Serial my_serial(argv[1], 9600, serial::Timeout::simpleTimeout(24));

  uint8_t bob = 1;
  while(1){
    my_serial.write(&bob, 1);
  }
}

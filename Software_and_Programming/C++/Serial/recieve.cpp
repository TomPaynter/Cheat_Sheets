#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <iomanip>
#include "serial/serial.h"

using namespace std;

int main(int argc, char **argv) {

  serial::Serial my_serial(argv[1], 9600, serial::Timeout::simpleTimeout(24));

  while(1){
    uint8_t inbyte;
    my_serial.read(&inbyte, 1);

    cout << (int)inbyte << ", ";
    
    }
  }

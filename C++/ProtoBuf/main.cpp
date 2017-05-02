/*add_part.cc*/
#include <iostream>
#include <fstream>
#include <string>
#include "partbook.pb.h"
using namespace std;

int main(void) {

  GOOGLE_PROTOBUF_VERIFY_VERSION;

  tutorial::Part nupart;

  nupart.set_name("Poop", 4);
  nupart.set_partid(7);

  string serialised_String = nupart.SerializeAsString();

  tutorial::Part oldpart;

  oldpart.ParseFromString(serialised_String);
  cout << "ID: " << oldpart.partid() << " " << oldpart.name() << endl;


  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include "json.hh"
#include <fstream>

#include <string>
#include <fstream>
#include <streambuf>


using namespace std;
using nlohmann::json;

int main(void) {
json config =  R"({  "pi": 3.141,"happy": true,  "name": "Niels",  "nothing": null,  "answer": {    "everything": 42  },  "list": [1, 0, 2],"object": {    "currency": "USD",    "value": 42.99  }})"_json;


cout << config["name"].get<std::string>() << endl;
cout << (int)config["pi"].get<uint8_t>() << endl;
cout << (float)config["pi"].get<float>() << endl;


std::ifstream ifs("../config.json");
std::string jsonstr((std::istreambuf_iterator<char>(ifs)),
                 std::istreambuf_iterator<char>());

cout << jsonstr << endl;

auto configfile = json::parse(jsonstr);

cout << configfile["red"].get<std::string>() << endl;

}

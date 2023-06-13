#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <thread>

using namespace std;

bool uplinkConnected = false;
string ipAddress;

// this will delay the print messages to seem like the termainal is actuly
// processing information
void delayPrint(const string &text) {
  cout << text;
  this_thread::sleep_for(chrono::milliseconds(50));
}

void commandMessageLine(const string &command, const string &description,
                        int spacing = 15) {
  cout << setw(spacing) << left << command;
  delayPrint(description);
}

void errorMessage(string tempInput) {
  delayPrint(tempInput);
  delayPrint(" is not recognized as a command");
  cout << endl;
}

void helpMessage() {
  cout << endl;
  delayPrint("Use the keyboard to write commands.");
  cout << endl;
  delayPrint("Use [Enter/Return] to excuite commands.");
  cout << endl;
  delayPrint("Use [Backspace] to erase an character");
  cout << endl;
  delayPrint("Use [Up Arrow] to traverse your earlier executed commands.");
  cout << endl;
  delayPrint("Press [Esc] to Exit");
  cout << endl;
  cout << endl;
  delayPrint("Type \"commands\" to get a list of all available commands");
  cout << endl;
  cout << endl;
}

void commandMessage() {
  cout << endl;
  cout << setw(25) << left << "help"
       << "Show the help screen" << endl;
  delayPrint("");
  cout << setw(25) << left << "commands"
       << "Show this command list" << endl;
  delayPrint("");
  cout << setw(25) << left << "uplink_connect"
       << "Establish an exterinal uplink connection" << endl;
  delayPrint("");
  cout << setw(25) << left << "uplink_verify"
       << "Verify the exterinal uplink connection to be able to connect"
       << endl;
  cout << endl;
}

void uplinkChecker(string ipAddressInput){
  if(uplinkConnected == true){
    delayPrint("This command only allows one use. Command has already been called.");
    cout << endl;
  }
  else if(ipAddressInput != ipAddress){
    delayPrint("Unknown address");
    cout << endl;
  }
  else{
    uplinkConnected = true;
    delayPrint("Creating exterinal uplink to address ");
    delayPrint(ipAddress);
    cout << endl;
    delayPrint("Initinal Uplink establish, awaiting verification key.");
    cout << endl;
    cout << endl;
    
    this_thread::sleep_for(chrono::milliseconds(400));
    cout << "\033[33m" << "WARNING! Breach detected!" << endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout << "\033[33m" << "WARNING! Breach detected!" << endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout << "\033[33m" << "WARNING! Breach detected!" << endl;;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout << "\033[0m";
    cout << endl;
  }
}

void messageChecker(const string &userInput) {
  if (userInput == "help") {
    helpMessage();
  } else if (userInput == "commands") {
    commandMessage();
  } else if (userInput.find("uplink_connect ") == 0) {
    string ipAddressInput = userInput.substr(15);
    uplinkChecker(ipAddressInput);
  }

  else {
    errorMessage(userInput);
  }
}

int main() {
  // generator random ip address with format of xxx.xxx.xxx.xxx
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist(100, 255);
  uniform_int_distribution<int> distLast(10, 255);

  int firstSet = dist(gen);
  int secondSet = dist(gen);
  int thirdSet = dist(gen);
  int lastSet = distLast(gen);

  ostringstream ipAddressStream;
  ipAddressStream << firstSet << "." << secondSet << "." << thirdSet << "."
                  << lastSet;

  ipAddress = ipAddressStream.str();

  delayPrint("Create an uplink to ");
  delayPrint(ipAddress);
  cout << endl;

  string userInput;
  while (true) {
    getline(cin, userInput);
    messageChecker(userInput);
  }

  return 0;
}

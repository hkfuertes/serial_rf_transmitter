#include <RCSwitch.h>
#include <ArduinoJson.h>
#define data_pin 2

RCSwitch mySwitch = RCSwitch();
String command;

void setup() {  
  Serial.begin(9600);
  Serial.println("Starting...");
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(data_pin);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');

    // say what you got:
    Serial.print("Sending: ");
    Serial.println(command);
    Serial.println(String(strtol(command.c_str(), NULL, 16)));

    //send the code
    mySwitch.send(strtol(command.c_str(), NULL, 16), 24);
  }
  
}

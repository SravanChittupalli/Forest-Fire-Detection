#include <SPI.h>
#include <ArduinoJson.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   7
#define CSN_PIN 8

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[4]; // this must match dataToSend in the TX
bool newData = false;

//===========

void setup() {
  
    Serial.begin(9600);

//    Serial.println("SimpleRx Starting");
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.startListening();
}

//=============

void loop() {
    getData();
    showData();
}

//==============

void getData() {
    if ( radio.available() ) {
        radio.read( &dataReceived, sizeof(dataReceived) );
        newData = true;
    }
}

void showData() {
    if (newData == true) {
//        Serial.print("Data received ");

        DynamicJsonDocument doc(1024); // ArduinoJson version 6+

        String Temperature = String(dataReceived[0]);
        String temp = String(dataReceived[1]);
        Temperature.concat(temp);
        doc["Temp"] = Temperature;

        String Humidity = String(dataReceived[2]);
        String humi = String(dataReceived[3]);
        Humidity.concat(humi);
        doc["Humi"] = Humidity;

        serializeJson(doc,Serial);
        Serial.println();
        newData = false;
    }
}

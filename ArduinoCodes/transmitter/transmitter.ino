

// SimpleTx - the master or the transmitter

//Libraries
#include <DHT.h>;
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


//Constants
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

#define CE_PIN   7
#define CSN_PIN 8

const byte slaveAddress[5] = {'R','x','A','A','A'};


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[4] = "2791";


unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second


void setup() {

    Serial.begin(9600);
    
    //starting dht
    dht.begin();

    Serial.println("SimpleTx Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openWritingPipe(slaveAddress);
}

//====================

void loop() {
    currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
        send();
        prevMillis = millis();
    }
    delay(15000);
}

//====================

void send() {

    bool rslt;
    rslt = radio.write( &dataToSend, sizeof(dataToSend) );
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    Serial.print("Data Sent ");
    Serial.print(dataToSend[0]);
    Serial.print(dataToSend[1]);
    Serial.print(dataToSend[2]);
    Serial.print(dataToSend[3]);
    if (rslt) {
        Serial.println("  Acknowledge received");
        updateMessage();
    }
    else {
        Serial.println("  Tx failed");
    }
}

//================

void updateMessage() {
    // so you can see that new data is being sent
    //String randomTemp = String(random(20, 99)); 
    //String randomHumid = String(random(20, 99));

    String hum = String((int)dht.readHumidity());
    String temp= String((int)dht.readTemperature());
    
    dataToSend[0] = temp[0];
    dataToSend[1] = temp[1];

    dataToSend[2] = hum[0];
    dataToSend[3] = hum[1];
}

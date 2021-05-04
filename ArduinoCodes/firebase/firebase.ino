/**
 * Created by K. Suwatchai (Mobizt)
 * 
 * Email: k_suwatchai@hotmail.com
 * 
 * Github: https://github.com/mobizt
 * 
 * Copyright (c) 2021 mobizt
 *
*/

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>
# include <ArduinoJson.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "Srav"
#define WIFI_PASSWORD "izukuMidoria"

/* 2. Define the Firebase project host name and API Key */
#define FIREBASE_HOST "https://forestfire-6a920-default-rtdb.firebaseio.com/"
#define API_KEY "AIzaSyDGLoCJ_PIkygy3desRgyH5nrW6P3cNmzM"

/* 3. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "forestfireess@gmail.com"
#define USER_PASSWORD "forestfireessgroup15"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

FirebaseJson json;

void printResult(FirebaseData &data);

int i = 0;

void setup()
{

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the project host and api key (required) */
  config.host = FIREBASE_HOST;
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
//////////////////////////////////////////////////

void loop()
{
  DynamicJsonDocument doc(1024);
  double temperature, humidity;
  
  boolean messageReady = false;
  String message = "";

  while(messageReady==false)
  {
    if(Serial.available())
    {
      message = Serial.readString();
      messageReady = true;
    }
  }
  Serial.println("Got message");
  DeserializationError error = deserializeJson(doc, message);
  Serial.println("Checked Error");
  if(error) 
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  temperature = doc["Temp"];
  humidity = doc["Humi"];
  Serial.println(temperature);
  Serial.println(humidity);
  #if defined(ESP8266)
  //Set the size of WiFi rx/tx buffers in the case where we want to work with large data.
  fbdo.setBSSLBufferSize(1024, 1024);
  #endif

  fbdo.setResponseSize(1024);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.RTDB.setReadTimeout(&fbdo, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.RTDB.setwriteSizeLimit(&fbdo, "tiny");

  //optional, set the decimal places for float and double data to be stored in database
  Firebase.setFloatDigits(2);
  Firebase.setDoubleDigits(6);

  String path = "/Test";
  String Path;

  Serial.println("------------------------------------");

  Path = path + "/Data";
  
  json.clear().add("Temperature", temperature);
  json.add("Humidity", humidity);

  if (Firebase.RTDB.pushJSON(&fbdo, Path.c_str(), &json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.print("PUSH NAME: ");
      Serial.println(fbdo.pushName());
      Serial.println("ETag: " + fbdo.ETag());
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
   i++;
 }

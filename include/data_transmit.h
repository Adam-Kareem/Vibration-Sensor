#ifndef DATATRANSMIT
#define DATATRANSMIT

//Wi_Fi
#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "ESP32-Vibration.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyD-gFg0FZiEjWY1z0EQiPgDKTE_MJkygKs"
#define WIFI_SSID "AH"
#define WIFI_PASSWORD "123456789"

FirebaseData firebaseData;
WiFiClient client;

String Wi_fi_Output; //WiFi Status
String Data_Output;  //Data Status

void auth_setup()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

/*
void fb_payload()
{

    Firebase.setTimestamp(firebaseData, path + "/Set/Timestamp")




}

if (Firebase.setTimestamp(firebaseData, path + "/Set/Timestamp"))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());

    //Timestamp saved in millisecond, get its seconds from intData()
    Serial.print("TIMESTAMP (Seconds): ");
    Serial.println(firebaseData.intData());

    //Or print the total milliseconds from doubleData()
    //Due to bugs in Serial.print in Arduino library, use printf to print double instead.
    printf("TIMESTAMP (milliSeconds): %.0lf\n", firebaseData.doubleData());

    //Or print it from payload directly
    Serial.print("TIMESTAMP (milliSeconds): ");
    Serial.println(firebaseData.payload());

    //Due to some internal server error, ETag cannot get from setTimestamp
    //Try to get ETag manually
    Serial.println("ETag: " + Firebase.getETag(firebaseData, path + "/Set/Timestamp"));
    Serial.println("------------------------------------");
    Serial.println();
  }

*/

#endif //DATATRANSMIT
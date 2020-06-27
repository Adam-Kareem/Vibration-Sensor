#ifndef DATATRANSMIT
#define DATATRANSMIT

#define Mhz_to_s 160000000

//Wi_Fi
#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://esp32-test-1e21e.firebaseio.com/"
#define FIREBASE_AUTH "cRM15BaTtSka6UzFBnNUSNXpffg4OX6Oi9FIvmzH"
#define WIFI_SSID "AH"
#define WIFI_PASSWORD "123456789"

FirebaseData firebaseData;
WiFiClient client;

String Wi_fi_Output; //WiFi Status
String Data_Output;  //Data Status

int j = 0;

void auth_setup()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    display_pos[0] = "Attempting WiFi connect";
    ui.update();
  }

  display_pos[0] = "Connected with IP:";
  display_pos[1] = WiFi.localIP().toString();
  ui.update();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  if (Firebase.pushTimestamp(firebaseData, "Connection/Timestamp"))
  {
    display_pos[2] = "Set Firebase timestamp";
  }

  /* buggy 
  else
  {
    display_pos[2] = "Firebase error";
    display_pos[3] = firebaseData.errorReason();
  }*/

  ui.update();
}

#endif //DATATRANSMIT
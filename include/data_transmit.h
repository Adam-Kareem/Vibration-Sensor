//Author : Adam Hussain

#ifndef DATATRANSMIT
#define DATATRANSMIT

//pins 15 (SCL) and 4 (SDA) for I2C

#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://esp32-test-1e21e.firebaseio.com/"
#define FIREBASE_AUTH "cRM15BaTtSka6UzFBnNUSNXpffg4OX6Oi9FIvmzH"
#define WIFI_SSID "AH"
#define WIFI_PASSWORD "123456789"

FirebaseData firebaseData;
WiFiClient client;

/*Establish and check connection to WiFi & Firebase*/
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
    ui.update();
  }
}

/*PUSH all axis data using REST API*/
class F_REST
{
public:
  void Push(String folder_filepath, float data1, float data2, float data3)
  {
    Firebase.pushFloat(firebaseData, "/" + folder_filepath + "/X", data1);
    Firebase.pushFloat(firebaseData, "/" + folder_filepath + "/Y", data2);
    Firebase.pushFloat(firebaseData, "/" + folder_filepath + "/Z", data3);
    Firebase.pushTimestamp(firebaseData, "/" + folder_filepath + "/Timestamp");
  }
};

#endif //DATATRANSMIT

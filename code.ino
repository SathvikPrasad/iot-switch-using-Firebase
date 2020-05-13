
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "save-6026b.firebaseio.com"
#define FIREBASE_AUTH "YkLbwZCErCjHIhLRCgsiYfw8wfao5eDtVJUI9Iwl"

#define WIFI_SSID "Free Wifi"
#define WIFI_PASSWORD "reddy1980"



void setup() {
  Serial.begin(115200);
 
   pinMode(5, OUTPUT);
   digitalWrite(5, LOW);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  } 
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  digitalWrite(5, LOW);
}

int n = 0;

void loop() {

    delay(1000);

  Serial.print("value: ");
  Serial.println(Firebase.getInt("value"));
  int val = Firebase.getInt("value");
  
    digitalWrite(5,val);

  delay(1000);
Firebase.setInt("value", 1);
 if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  Serial.print("pushed: /logs/");

}

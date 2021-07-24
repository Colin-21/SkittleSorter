#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>


// Add sign in data then upload
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

FirebaseData firebaseData;

void setup() {Serial.begin(115200);
  Serial.println("Serial communication started\n\n");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);



  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }


  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() { 

// Firebase Error Handling And Writing Data At Specifed Path**


if (Firebase.setInt(firebaseData, "/data", val)) {    // On successful Write operation, function returns 1
               Serial.println("Value Uploaded Successfully");
               Serial.print("Val = ");
               Serial.println(val);
               Serial.println("\n");

               val++;
               delay(1000);

     }

else {
    Serial.println(firebaseData.errorReason());
  }

}


/* NOTE:
 *  To upload value, command is ===> Firebase.setInt(firebaseData, "path", variable);
 *  Example                     ===>  Firebase.setInt(firebaseData, "/data", val);
 */

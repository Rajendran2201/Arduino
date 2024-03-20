#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber = ;                // Channel ID
const char * myCounterReadAPIKey = "";      // Read API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
const int FieldNumber2 = 2;                                 // The field you wish to read

void setup()
{
  pinMode(2,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("", "");                 // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
 Serial.println(A);
 digitalWrite(2,A);
}


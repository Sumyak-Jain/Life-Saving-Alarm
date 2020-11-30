#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>

const char* ssid = "***"; //Your Network SSID
const char* password = "******"; //Your Network Password
int val;
int PulseSensorpin = A0; //Pulse Sensor Pin Connected at A0 Pin
int buzzer=8;

int PulseWire = 0;
int Threshold = 550;
PulseSensorPlayground pulseSensor;

WiFiClient client;
unsigned long start_time;
unsigned long time1;
unsigned long myChannelNumber = ******* ; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "***********"; //Your Write API Key

void setup()
{
 Serial.begin(9600);
 
 pulseSensor.analogInput(PulseWire);
pulseSensor.setThreshold(Threshold);
pulseSensor.begin();
 
 start_time=millis(); //Starting the timer
 
 delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password); //Connecting to the wifi
  ThingSpeak.begin(client);// beginning thingspeak
}

void loop()
{
 
 val = pulseSensor.getBeatsPerMinute(); // Calls function on our pulseSensor object that returns BPM as an "int".

 int flag=1; //counter variable to check the condition
  //val = (analogRead(PulseSensorpin)); //Read Analog values and Store in val variable
  Serial.println("Pulse Sensorvalue=  "); // Start Printing on Pulse sensor value on LCD
  Serial.println(val); // Start Printing on Pulse sensor value on LCD
  delay(10);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
 
   if(val<=635 || val >=520)
  {
  while(flag==1)
  {
    time1=millis();
    if((time1-start_time)>=060000)
    {
    Serial.print("Critical condition");
    digitalWrite(buzzer, HIGH);
    while (get_http(String("Critical")) != 0);
    }
    if(val<=635 || val>=520)
    {
      flag=0;
      break;
  }
}
}
  digitalWrite(buzzer,LOW);
 
  
}
int get_http(String state)
{
   HTTPClient http;
   int ret = 0;
   Serial.print("[HTTP] begin...\n");
   // configure ifttt server and url  should be HTTP only..not https!!!  (http://)   
    //http.begin("https://maker.ifttt.com/trigger/Pulse sensor/with/key/fnaGeMWtqDtLb0fR7xZXWVu1ItGam_P13cdnqCPzo2g"); //HTTP
   //If you have enabled value1 from iftt settings then uncomment below line to send value and comment out above line  
   http.begin("http://maker.ifttt.com/trigger/Pulse sensor/with/key/fnaGeMWtqDtLb0fR7xZXWVu1ItGam_P13cdnqCPzo2g/?value1="+state); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();
    // httpCode will be negative on error
    if(httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET code: %d\n", httpCode);

      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
        ret = -1;
        Serial.printf("[HTTP] GET failed, error: %s\n", http.errorToString(httpCode).c_str());
        delay(500); // wait for half sec before retry again
    }

    http.end();
    return ret;
}  

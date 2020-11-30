#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

int UpperThreshold = 518;
    int LowerThreshold = 490;
    int reading = 0;
    float BPM = 0.0;
    bool IgnoreReading = false;
    bool FirstPulseDetected = false;
    unsigned long FirstPulseTime = 0;
    unsigned long SecondPulseTime = 0;
    unsigned long PulseInterval = 0;


const char* ssid = "***"; //Your Network SSID
const char* password = "*******"; //Your Network Password
int val;
int PulseSensorpin = A0; //Pulse Sensor Pin Connected at A0 Pin
int buzzer=8;

WiFiClient client;
unsigned long start_time;
unsigned long time1;
unsigned long myChannelNumber = *** ; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey ="*******"; //Your Write API Key

void setup()
{
 Serial.begin(9600);
 start_time=millis(); //Starting the timer
 
 delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password); //Connecting to the wifi
  ThingSpeak.begin(client);// beginning thingspeak
}

void loop()
{

  reading = analogRead(0); 

      // Heart beat leading edge detected.
      if(reading > UpperThreshold && IgnoreReading == false){
        if(FirstPulseDetected == false){
          FirstPulseTime = millis();
          FirstPulseDetected = true;
        }
        else{
          SecondPulseTime = millis();
          PulseInterval = SecondPulseTime - FirstPulseTime;
          FirstPulseTime = SecondPulseTime;
        }
        IgnoreReading = true;
      }

      // Heart beat trailing edge detected.
      if(reading < LowerThreshold){
        IgnoreReading = false;
      }  

      BPM = (1.0/PulseInterval) * 60.0 * 1000;

  
      Serial.print(BPM);
      Serial.println(" BPM");
      Serial.flush();

      // Please don't use delay() - this is just for testing purposes.
      delay(50);
      
 int flag=1; //counter variable to check the condition
 // val = (analogRead(PulseSensorpin)); //Read Analog values and Store in val variable
  Serial.println("Pulse Sensorvalue=  "); // Start Printing on Pulse sensor value on LCD
  
  delay(10);
  ThingSpeak.writeField(myChannelNumber, 1,BPM, myWriteAPIKey); //Update in ThingSpeak
 
  if(BPM<=140 || BPM >=55)
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
    if(BPM<=140 || BPM>=55)
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

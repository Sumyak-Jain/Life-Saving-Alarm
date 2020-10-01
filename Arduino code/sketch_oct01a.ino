unsigned long start_time;
unsigned long time2;
int pulse_sensor = A0;   
int buzzer = 8;
void setup() {
  
Serial.begin(9600);  
start_time=  millis(); //current time 
  pinMode(pulse_sensor,INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int flag=0;int flag2=0;
 
 //Serial.print(time1);
 if(analogRead(pulse_sensor)<=55 || analogRead(pulse_sensor)>=140)
 {
  while(1)
  {
   time2 = millis();
   //Serial.print(time2);
   //Serial.println("");
   if((time2-start_time) >= 060000)
   {
    flag=1;
    break;
   }
   if(analogRead(pulse_sensor)>=55 || analogRead(pulse_sensor)<=140)
   {
    //Serial.print(analogRead(pulse_sensor));
    Serial.println("");
    flag2=1;
    break;
   }
   if(analogRead(pulse_sensor<=40 || analogRead(pulse_sensor)>=150)
   {
    flag=1;
    break;
   }
  }
 }
 
  digitalWrite(buzzer,LOW);
  delay(1000);
  Serial.print(" LOW ");
  Serial.println("");
  if (flag==1 && flag2==0)
  {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    Serial.print(" HIGH ");
    Serial.println("");
 
  }
 
}

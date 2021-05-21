#define BLYNK_PRINT Serial
#include<Wire.h>
#include<RTClib.h>
#include<Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "6fQsyz4qmhprC-CooUiC6I-qE5WFNW_v";

RTC_DS1307 rtc;
Servo myservo;
int mini=0;
int target=30;


char ssid[] = "DeadPOOL";
char pass[] = "shifat55555";

void setup()
{
  
  Serial.begin(9600);
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  Blynk.begin(auth, ssid, pass);
  myservo.attach(D8);
  
}

void loop()
{
  Blynk.run();

  DateTime present = rtc.now();
  mini = present.minute();
  Serial.print(present.hour());
  Serial.print(":");
  Serial.print(present.minute());
  Serial.print(":");
  Serial.println(present.second());
  
  if(mini==target)
  {
    for(int i=0; i<8;i++)
    {
      delay(400);
      myservo.write(90);
      delay(500);
      myservo.write(120);
      delay(500);
      myservo.write(150);
      delay(500);
    }
      target=target+1;
  }
  if(target==60)
  {
    target=0;
  }
  Serial.println(target);
  
}


BLYNK_WRITE(V2)
{
  for(int i=0; i<3;i++)
    {
      delay(400);
      myservo.write(90);
      delay(500);
      myservo.write(120);
      delay(500);
      myservo.write(150);
      delay(400);
    }
}

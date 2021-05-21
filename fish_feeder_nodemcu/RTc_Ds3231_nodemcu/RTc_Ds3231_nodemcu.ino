#include<Wire.h>
#include<RTClib.h>

RTC_DS1307 rtc;
int mini = 0;

void setup() {
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  Serial.begin(9600);
  

}

void loop() {
  DateTime present = rtc.now();
  mini = present.minute();
  Serial.print(present.hour());
  Serial.print(":");
  Serial.print(present.minute());
  Serial.print(":");
  Serial.println(present.second());
  delay(1000);

}

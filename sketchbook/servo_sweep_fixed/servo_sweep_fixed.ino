#include <Servo.h>
Servo servo1;//create servo object to control a servo
void setup()
{
  servo1.attach(9);//attachs the servo on pin 9 to servo object
  delay(1000);//wait for a second
}

void loop()
{
  servo1.write(180);//goes to 180 degrees
  delay(2000);//wait for two seconds

  servo1.write(90);//goes to 90 degrees
  delay(2000);//wait for two seconds
  
  servo1.write(0);//goes to 0 degrees
  delay(2000);//wait for two seconds

  servo1.write(90);//goes to 90 degrees
  delay(2000);//wait for two seconds
}

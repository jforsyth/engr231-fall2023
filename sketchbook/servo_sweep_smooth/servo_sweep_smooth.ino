#include <Servo.h>
Servo sevro1;//create servo object to control a servo
void setup()
{
  sevro1.attach(9);//attachs the servo on pin 9 to servo object
  delay(1000);//wait for a second
}

const int min_angle=0;
const int max_angle=180;
const int angle_delta = 5;
const int time_delta = 10;

void loop()
{

  // start from a minimum angle and move to a maximum angle
  // based upon some angle delta and time delta
  for(int angle=min_angle;angle<max_angle;angle+=angle_delta)
  {
    sevro1.write(angle);
    delay(time_delta);
  }

  for(int angle=max_angle;angle>min_angle;angle-=angle_delta)
  {
    sevro1.write(angle);
    delay(time_delta);
  }
  
}

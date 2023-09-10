//include the servo library
#include <Servo.h>

//create servo objects for all motors
Servo servo1;

//manually define which pin controls each servo
//the appropriate pin is indicated by the lettering on the board
//e.g. D9/Servo1 indicate servo1 is attached to pin 9.
int servopin1 = 9;

void setup()
{

  // configure all servo pins as OUTPUTS
  pinMode(servopin1, OUTPUT); 

  //for each servo, attach it to the correct Arduino pin
  servo1.attach(servopin1);

  // command each servo to go to 90 degrees
  servo1.write(90);

}


void loop()
{

  // do nothing here...

}

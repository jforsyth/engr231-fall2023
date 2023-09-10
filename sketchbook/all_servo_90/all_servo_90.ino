//include the servo library
#include <Servo.h>

//create servo objects for all motors
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

//manually define which pin controls each servo
//the appropriate pin is indicated by the lettering on the board
//e.g. D9/Servo1 indicate servo1 is attached to pin 9.
int servopin1 = 9;
int servopin2 = 6;
int servopin3 = 5;
int servopin4 = 3;
int servopin5 = 11;


void setup()
{

  // configure all servo pins as OUTPUTS
  pinMode(servopin1, OUTPUT); 
  pinMode(servopin2, OUTPUT); 
  pinMode(servopin3, OUTPUT); 
  pinMode(servopin4, OUTPUT); 
  pinMode(servopin5, OUTPUT); 

  //for each servo, attach it to the correct Arduino pin
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);

  // command each servo to go to 90 degrees
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);

}


void loop()
{

  // do nothing here...

}

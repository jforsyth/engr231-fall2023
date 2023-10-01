/***********************************************************
Automation Example - JF 10/1/23
***********************************************************/
#include <Servo.h>

// create five different servo motor objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// enumerate each pin from the Arduino for each servo motor
const int servo1_pin = 9;
const int servo2_pin = 6;
const int servo3_pin = 5;
const int servo4_pin = 3;
const int servo5_pin = 11;

// enumerate each analog input pin each potentiometer is connected on the Arduino
const int pot1_pin = A0;
const int pot2_pin = A1;
const int pot3_pin = A2;
const int pot4_pin = A3;
const int pot5_pin = A6;

// set initial angular positions for the servo motors
const int servo1_initial_position = 90;
const int servo2_initial_position = 90;
const int servo3_initial_position = 90;
const int servo4_initial_position = 90;
const int servo5_initial_position = 90;

/*
* Move a servo motor to a particular angle (in degrees) at a certain speed (degress/second)
*/
void move_servo_at_speed(Servo& servo, int angle, int speed)
{
  // move to the new angle based upon millisecond tick interval
  const int step_interval = 10;

  

}

void setup()
{
  
  // set potentiometer ports to inputs
  pinMode(pot1_pin, INPUT);
  pinMode(pot2_pin, INPUT);
  pinMode(pot3_pin, INPUT);
  pinMode(pot4_pin, INPUT);
  pinMode(pot5_pin, INPUT);
  
  // attach all servo objects to their correct pins
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo3.attach(servo3_pin);
  servo4.attach(servo4_pin);
  servo5.attach(servo5_pin);
  
  // command the servos to go to their initial position
  servo1.write(servo1_initial_position);//goes to dataServo1 degrees 
  servo2.write(servo2_initial_position);//goes to dataServo2 degrees 
  servo3.write(servo3_initial_position);//goes to dataServo3 degrees 
  servo4.write(servo4_initial_position);//goes to dataServo4 degrees 
  servo5.write(servo5_initial_position);//goes to dataServo5 degrees 

  // initialize the serial port at 115200 baud
  Serial.begin(115200);
}
void loop()
{

  // read the value from all the potentiometers
  int pot1_reading = analogRead(pot1_pin);
  int pot2_reading = analogRead(pot2_pin);
  int pot3_reading = analogRead(pot3_pin);
  int pot4_reading = analogRead(pot4_pin);
  int pot5_reading = analogRead(pot5_pin);

  // convert those values [0,1023] into angles [0,180] 
  int angle1 = map(pot1_reading, 0, 1023, 0, 180);  
  int angle2 = map(pot2_reading, 0, 1023, 0, 180);  
  int angle3 = map(pot3_reading, 0, 1023, 0, 180);  
  int angle4 = map(pot4_reading, 0, 1023, 0, 180);  
  int angle5 = map(pot5_reading, 0, 1023, 0, 180);  

  // command each motor to its angle
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  servo5.write(angle5);

  // print out all the angles to the screen
  Serial.print("Pot1: "); Serial.print(angle1);
  Serial.print("\tPot2: "); Serial.print(angle2);
  Serial.print("\tPot3: "); Serial.print(angle3);
  Serial.print("\tPot4: "); Serial.print(angle4);
  Serial.print("\tPot5: "); Serial.println(angle5);

  // delay 50 ms 
  delay(50);
}

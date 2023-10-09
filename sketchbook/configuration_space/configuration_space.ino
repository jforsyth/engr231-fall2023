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

void setup() {

  // initialize the serial port at 115200 baud
  Serial.begin(115200);

  // attach all servo objects to their correct pins
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo3.attach(servo3_pin);
  servo4.attach(servo4_pin);
  servo5.attach(servo5_pin);

  // wait 1s for motors to activate
  delay(1000);
}

/*
* Function to adjust servo movement speed. Modify at your own risk...there be dragons...
*/
void move_servo_to(Servo& motor, int target_position, int step_delay)
{
  // assume a constant step size of 1 degree
  const int step_size = 1;

  // check that a good value for the step delay is passed
  if(step_delay<=0)
  {
    step_delay = 50;
  }

  // ensure the value passed is between [0,180]
  target_position = target_position%180;

  // keep a flag of whether movement is complete
  // loop until done
  boolean movement_complete = false;
  while (!movement_complete)
  {
    // get the current position of the motor
    int current_position = motor.read();

    // calculate how far the motor should rotate until the target
    int distance = current_position - target_position;

    // if the |distance| is less than the step_size, just go there
    if (abs(distance) < step_size || distance == 0)
    {
      motor.write(target_position);
      movement_complete = true;
    }
    else
    {

      //this should occur but we should check anyways
      if (distance == 0)
      {

        //...we're here... so do nothing
        movement_complete = true;

      }
      // if the distance is negative then increment by step size
      else if (distance < 0)
      {
        motor.write(current_position + step_size);
      }

      // the distance must be positve then decrement by the step size
      else
      {
        motor.write(current_position - step_size);
      }
    }

    // do not move again until the delay is complete
    delay(step_delay);
  }
}


void loop()
{

  /*
     Part 1: Manually set the configuration of the arm via individual servo.write() commands
     Note: the arm will move to this configuration "as fast as possible"
  */

  // uncomment these lines and place in your own values
  //servo1.write(114);
  //servo2.write(85);
  //servo3.write(0);
  //servo4.write(0);
  //servo5.write(93);

  /**
     Part 2: Use move_servo_to to set the position of each servo. The function has three parameters
     Servo Name: this must match the list of Servo objects from the top of the program
     Target Position: the angle the motor is to be set to. Value should be [0,180] degrees
     Step Size: the time interval in milliseconds between which the motor will "step" a fixed distance. The smaller the step size, the "faster" the motor will approach
     its target position. Recommend values are: 50 - very slow, 20 - medium/smooth, 10 - fast
     
  */

  // uncomment these lines and place in your own values
  // move to the first configuration
  move_servo_to(servo1, 120, 10);
  move_servo_to(servo2,85,10);
  move_servo_to(servo3,0,10);
  move_servo_to(servo4,0,10);
  move_servo_to(servo5,93,10);

  // hold their for one second
  delay(1000);

  // uncomment these lines and place in your own values
  // move to the second configuration that is a short distane away
  //move_servo_to(servo1, 120, 10);
  //move_servo_to(servo2,85,10);
  //move_servo_to(servo3,0,10);
  //move_servo_to(servo4,0,10);
  //move_servo_to(servo5,60,10);

  // hold their for one second
  delay(1000);

  // repeat the loop...

}

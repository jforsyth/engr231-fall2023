#include <Servo.h>

// create five different servo motor objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// create an array of servo pointers
Servo* servoArray[] = {&servo1,&servo2, &servo3, &servo4, &servo5};
const int num_motors = 5;

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

void move_servo_to(Servo& motor, int target_position, int step_delay)
{
  // assume a constant step size
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
      // if the distance is negative then decrement by step size
      else if (distance < 0)
      {
        motor.write(current_position + step_size);
      }

      // the distance must be positve
      else
      {
        motor.write(current_position - step_size);
      }
    }

    // do not move again until the delay is complete
    delay(step_delay);
  }
}

void set_arm_configuration(Servo* servos[], int positions[])
{
  for(int i=0;i<num_motors;i++)
  
}

void loop()
{

  
  int positions[]={114,85,0,0,93};
  set_arm_configuration(servoArray, positions);

  // repeat the loop...

}

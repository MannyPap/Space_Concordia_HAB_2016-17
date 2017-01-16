#include <Servo.h>

Servo esc;

void setup()
{
  setup_ACS();
  esc.attach(9); //pin used for esc signal on arduino
  esc.writeMicroseconds(1060); //arm the motor to zero speed, failing to do this will crank the motor to 100% on startup
  delay(1000);
  }

void loop()
{
  loop_ACS();
  int val;
  val = TO_DEG(yaw);
  val = map(val,-180,+180, 1060,1860); //1860 is max
  esc.writeMicroseconds(val);
}


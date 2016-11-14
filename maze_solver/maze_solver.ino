#include <Servo.h>

Servo leftServo; 
Servo rightServo; 

const int SPEED = 20;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  angelasWay();
  // dansWay();
}

void angelasWay() {
  if (deadEnd())
    turnAround();
  else if (!wallOnLeft())
    turnLeft();
  else if (wallAhead())
    turnRight();
  else
    moveForward();
}

void dansWay() {
  if (!wallOnLeft())
    turnLeft();
  else if (wallAhead())
    turnRight();
  else
    moveForward();
}

boolean deadEnd() {
  return wallOnLeft() && wallOnRight() && wallAhead();
}

boolean wallOnLeft() {
  return false;
}

boolean wallOnRight() {
  return false;
}

boolean wallAhead() {
  return false;
}

void turnLeft() {
  // servoLeft = -20
  // servoRight = 20
  setLeftServoSpeed(SPEED * -1);
  setRightServoSpeed(SPEED);
}

void turnRight() {
  // servoLeft = 20
  // servoRight = -20
  setLeftServoSpeed(SPEED);
  setRightServoSpeed(SPEED * -1);
}

void moveForward() {
  setLeftServoSpeed(SPEED);
  setRightServoSpeed(SPEED);
}

void turnAround() {
  
}

void stopRobot() {
  setLeftServoSpeed(0);
  setRightServoSpeed(0);
}

void setLeftServoSpeed(int speed) {
  leftServo.write(speed);
}

void setRightServoSpeed(int speed) {
  rightServo.write(speed);
}

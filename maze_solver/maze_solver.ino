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
  
}

void turnRight() {
  
}

void moveForward() {
  
}


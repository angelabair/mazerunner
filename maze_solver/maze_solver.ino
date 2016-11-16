

// Included libraries
<<<<<<< HEAD
//#include <Servo.h>                  // Include Servo library -  We're not using servos
=======
#include <Servo.h>                    // Include Servo library
>>>>>>> e587d14dfebecb24ac9d27755b056a1be741dd6b
#include <NewPing.h>                  // Include NewPing ultrasonic sensor library

#define SONAR_NUM 3;                  // Number of sensors
#define MAX_DISTANCE 30;              // Max distance in cm
#define PING_INTERVAL 33;             // Milliseconds between pings

// Variable initialization
unsigned long pingTimer[SONAR_NUM];   // When each pings
unsigned int cm[SONAR_NUM];           // Store ping distances
uint8_t currentSensor = 0;            // Which sensor is active.

<<<<<<< HEAD
//const int SPEED = 20;               // Set speed of servos

// Library initialization
//Servo leftServo;                    // Declare left servo
//Servo rightServo;                   // Declare right servo

//Left motor initialization 
const int pwmLeft = 2 ;               // initializing pin 2 as pwm
const int in_1 = 8 ;                  // Inrializing logic pins
const int in_2 = 9 ;

//Right motor intialization
const int pwmRight = ;                // initializing pin # as pwm
const int in_3 = ;                    // Inrializing logic pins
const int in_4 = ;

NewPing sonar[SONAR_NUM] = {          // Object array for sensors
//   NewPing(trigger_pin, echo_pin, max_distance)
//   trig pins (13, 7
//   echo pins (
=======
//const int SPEED = 20;                 // Set speed of servos

// Library initialization
Servo leftServo;                      // Declare left servo
Servo rightServo;                     // Declare right servo

NewPing sonar[SONAR_NUM] = {          //Object array for sensors
  //NewPing(trigger_pin, echo_pin, max_distance)
>>>>>>> e587d14dfebecb24ac9d27755b056a1be741dd6b
  NewPing(11, 12, MAX_DISTANCE),
  NewPing(13, 14, MAX_DISTANCE),
  NewPing(15, 16, MAX_DISTANCE)
}

<<<<<<< HEAD

=======
>>>>>>> e587d14dfebecb24ac9d27755b056a1be741dd6b
void setup() {                        // Built in initialization block
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
<<<<<<< HEAD
//  leftServo.attach(10);
//  rightServo.attach(11);
//  leftServo.write(90);              // Sets servo to mid-point
//  rightServo.write(90);
  pinMode(pwmLeft, OUTPUT);           //we have to set PWM pin as output
  pinMode(in_1, OUTPUT);  /           //Logic pins are also set as output 
  pinMode(in_2, OUTPUT);
 
  pingTimer[0] = millis() + 75;       // First ping start in ms.
=======
  leftServo.attach(10);
  rightServo.attach(11);
  leftServo.write(90);                // Sets servo to mid-point
  rightServo.write(90);
 
  pingTimer[0] = millis() + 75; // First ping start in ms.
>>>>>>> e587d14dfebecb24ac9d27755b056a1be741dd6b
  for (uint8_t i = 1; i < SONAR_NUM; i++)
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

}

void loop() {                         // Main loop
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    if (millis() >= pingTimer[i]) {
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;
      if (i == 0 && currentSensor == SONAR_NUM - 1)
        oneSensorCycle(); // Do something with results.
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      cm[currentSensor] = 0;
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }
  
<<<<<<< HEAD
//   delay(50);
//   angelasWay();
//   dansWay();}

void echoCheck() {                    // Checks ping echo and sets distance to array
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() {               // Moves depending on sensor results
  
  angelasWay();
  //dansWay();
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm ");
  }
  Serial.println();
}

=======
  // delay(50);
  // angelasWay();
  // dansWay();
}

void echoCheck() {                    // Checks ping echo and sets distance to array
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() {               // Moves depending on sensor results
  
  angelasWay();
  //dansWay();
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm ");
  }
  Serial.println();
}

>>>>>>> e587d14dfebecb24ac9d27755b056a1be741dd6b
void angelasWay() {                   // Includes block for deadend
  if (!wallOnLeft())
    turnLeft();
  delay(50);
  else if (wallAhead()) {
    if (wallOnRight())
      turnAround();
    delay(50);
    else
      turnRight();
    delay(50);
  }
  else
    moveForward();
  delay(50);
}

void dansWay() {                      // Only uses interval event turns
  if (!wallOnLeft())
    turnLeft();
  delay(50);
  else if (wallAhead())
    turnRight();
  delay(50);
  else
    moveForward();
  delay(50);
}

boolean deadEnd() {                   // Returns if there is a deadend
  return wallOnLeft() && wallOnRight() && wallAhead();
}

boolean wallOnLeft() {                // Returns if there is a wall on the left
  return false;
}

boolean wallOnRight() {               // Returns if there is a wall on the right
  return false;
}

boolean wallAhead() {                 // Returns if there is a wall ahead
  return false;
}

void turnLeft() {                     // Makes robot turn left
<<<<<<< HEAD
//  servoLeft = -20
//  servoRight = 20
//  setLeftServoSpeed(SPEED * -1);
//  setRightServoSpeed(SPEED);
//  setLeftServoSpeed(45);            // I don't know if any of these speeds actually work
//  setRightServoSpeed(135);          // Let's hope I didn't fuck up
  digitalWrite(in_1, HIGH);           // This should go backwards
  digitalWrite(in_2, LOW);
  analogWrite(pwmLeft, 255);          // This is full speed so it might be full circle
  delay(#);

  digitalWrite(in_1, HIGH);           // This should go forwards
  digitalWrite(in_2, LOW);
  analogWrite(pwmRight, 255);
  delay(#);
}

void turnRight() {                    // Makes robot turn right
//   servoLeft = 20
//   servoRight = -20
//  setLeftServoSpeed(SPEED);
//  setRightServoSpeed(SPEED * -1);
//  setLeftServoSpeed(135);
//  setRightServoSpeed(45);

  digitalWrite(in_1, LOW);            // This should go backwards
  digitalWrite(in_2, HIGH);
  analogWrite(pwmLeft, 255);          
  delay(#);                           // Change the delays for the rotation times

  digitalWrite(in_3, LOW);            // This should go forwards
  digitalWrite(in_4, HIGH);
  analogWrite(pwmRight, 255);
  delay(#);
}

void moveForward() {                  // Makes robot go forward
//  setLeftServoSpeed(SPEED);
//  setRightServoSpeed(SPEED);
//  setLeftServoSpeed(0);
//  setRightServoSpeed(0);

  digitalWrite(in_1, LOW);            
  digitalWrite(in_2, HIGH);
  analogWrite(pwmLeft, 255);
  delay(#);          

  digitalWrite(in_3, HIGH);           
  digitalWrite(in_4, LOW);
  analogWrite(pwmRight, 255);
  delay(#);
}

void turnAround() {                   // Makes robot turnaround
//  setLeftServoSpeed(0);
//  setRightServoSpeed(180);
  digitalWrite(in_1, HIGH);           
  digitalWrite(in_2, LOW);
  analogWrite(pwmLeft, 255);          
  delay(#);
  
  digitalWrite(in_3, HIGH);           
  digitalWrite(in_4, LOW);
  analogWrite(pwmRight, 255);
  delay(#);
}

void stopRobot() {                     // Makes robot stop
//  setLeftServoSpeed(90);
//  setRightServoSpeed(90);

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, HIGH);
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, HIGH);
  delay(#);
}

//void setLeftServoSpeed(int speed) {   // Sets speed of left servo
////  leftServo.write(speed);
//}
//
//void setRightServoSpeed(int speed) {  // Sets speed of right servo
////  rightServo.write(speed);
//}
=======
  // servoLeft = -20
  // servoRight = 20
  //setLeftServoSpeed(SPEED * -1);
  //setRightServoSpeed(SPEED);
  setLeftServoSpeed(45);              // I don't know if any of these speeds actually work
  setRightServoSpeed(135);            // Let's hope I didn't fuck up
}

void turnRight() {                    // Makes robot turn right
  // servoLeft = 20
  // servoRight = -20
  //setLeftServoSpeed(SPEED);
  //setRightServoSpeed(SPEED * -1);
  setLeftServoSpeed(135);
  setRightServoSpeed(45);
}

void moveForward() {                  // Makes robot go forward
  //setLeftServoSpeed(SPEED);
  //setRightServoSpeed(SPEED);
  setLeftServoSpeed(0);
  setRightServoSpeed(0);
}

void turnAround() {                   // Makes robot turnaround
  setLeftServoSpeed(0);
  setRightServoSpeed(180);
}

void stopRobot() {                    // Makes robot stop
  setLeftServoSpeed(90);
  setRightServoSpeed(90);
}

void setLeftServoSpeed(int speed) {   // Sets speed of left servo
  leftServo.write(speed);
}

void setRightServoSpeed(int speed) {  // Sets speed of right servo
  rightServo.write(speed);
}135
>>>>>>> e587d14dfebecb24ac9d27755b056a1be741dd6b

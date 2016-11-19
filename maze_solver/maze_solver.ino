// Included libraries
#include <NewPing.h>                  // Include NewPing ultrasonic sensor library

#define SONAR_NUM 3                   // Number of sensors
#define MAX_DISTANCE 30               // Max distance in cm
#define PING_INTERVAL 33              // Milliseconds between pings
#define DELAY_TIME 50

// Variable initialization
unsigned long pingTimer[SONAR_NUM];   // When each pings
unsigned int cm[SONAR_NUM];           // Store ping distances
uint8_t currentSensor = 0;            // Which sensor is active.

//Left motor initialization
const int in_1 = 13;                  // Inrializing logic pins
const int in_2 = A5;

//Right motor intialization
const int in_3 = 11;                    // Inrializing logic pins
const int in_4 = 12;

static NewPing sonar[SONAR_NUM] = {   // Object array for sensors
  //   NewPing(trigger_pin, echo_pin, max_distance)

  NewPing(7, 5, MAX_DISTANCE),        // Front sensor 
  NewPing(4, 2, MAX_DISTANCE),        // Left sensor
  NewPing(10, 8, MAX_DISTANCE)        // Right sensor
};

void setup() {                        // Built in initialization block
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(in_1, OUTPUT);              //Logic pins are also set as output
  pinMode(in_2, OUTPUT);  
  pinMode(in_3, OUTPUT);              //Logic pins are also set as output
  pinMode(in_4, OUTPUT);

//  pingTimer[0] = millis() + 75;       // First ping start in ms.
//  uint8_t i;
//  for (i = 1; i < SONAR_NUM; i++)
//    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

}

void loop() {                         // Main loop
  
  moveForward();
  
  uint8_t i;
  for (i = 0; i < SONAR_NUM; i++) {
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
}

// Checks ping echo and sets distance to array
void echoCheck() {                     
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() {                // Moves depending on sensor results

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

// Includes block for deadend
void angelasWay() {                    
  if (!wallOnLeft()) {
    turnLeft();
    delay(50);
  }
  else if (wallAhead()) {
    if (wallOnRight()) {
      turnAround();
      delay(50);
    }
    else {
      turnRight();
      delay(50);
    }
  }
  else {
    moveForward();
    delay(50);
  }
}

// Only uses interval event turns
void dansWay() {                       
  if (!wallOnLeft()) {
    turnLeft();
    delay(50);
  }
  else if (wallAhead()) {
    turnRight();
    delay(50);
  }
  else {
    moveForward();
    delay(50);
  }
}

// Returns true if there is a deadend
boolean deadEnd() {                    
  return wallOnLeft() && wallOnRight() && wallAhead();
}

// Returns true if there is a wall on the left
boolean wallOnLeft() {                 
  return cm[1] <= MAX_DISTANCE;
}

// Returns true if there is a wall on the right
boolean wallOnRight() {                
  return cm[2] <= MAX_DISTANCE;
}

// Returns true if there is a wall ahead
boolean wallAhead() {                  
  return cm[0] <= MAX_DISTANCE;
}

// Makes robot turn left
void turnLeft() {                      
  leftWheelBackwards();
  rightWheelForward();
}

// Makes robot turn right
void turnRight() {                     

  leftWheelForward();
  rightWheelBackwards();
}

// Makes robot go forward
void moveForward() {                   

  leftWheelForward();
  rightWheelForward();
}

// Makes robot turnaround
void turnAround() {                    
  digitalWrite(in_1, HIGH);
  analogWrite(in_2, LOW);
  delay(DELAY_TIME);

  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
  delay(DELAY_TIME);
}

// Makes robot stop
void stopRobot() {                     

  digitalWrite(in_1, HIGH);
  analogWrite(in_2, HIGH);
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, HIGH);
  delay(DELAY_TIME);
}

void leftWheelForward() {
  Serial.print("Moving left wheel forward");
  digitalWrite(in_1, LOW);             // This should go backwards
  digitalWrite(in_2, HIGH);
  delay(DELAY_TIME);
}

void leftWheelBackwards() {
  digitalWrite(in_1, HIGH);            // This should go backwards
  analogWrite(in_2, LOW);
  delay(DELAY_TIME);
}

void rightWheelForward() {
  Serial.write("Moving right wheel forward...");
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
  delay(DELAY_TIME);
}

void rightWheelBackwards() {
  digitalWrite(in_3, LOW);              // This should go forwards
  digitalWrite(in_4, HIGH);
  delay(DELAY_TIME);
}

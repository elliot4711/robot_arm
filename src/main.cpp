#include <Arduino.h>
#include <Stepper.h> 

// Defining pins for joystick controls and zeroing controller
// First thumb-stick
int JoyStick_X = 0; // x	
int JoyStick_Y = 1; // y	
int JoyStick_Z = 13; // key
int x_fix = 21; // x offset fix
int y_fix = 9; // y offset fix

// Second thumb-stick
int JoyStick_X2 = 2; // x2
int JoyStick_Y2 = 3; // y2
int JoyStick_Z2 = 12; // key2
int x2_fix = 4; // x2 offset fix
int y2_fix = 0 ; // y2 offset fix

// Amount of steps for a full revolution of big and small motors
int SmallStep = 4096;
int BigStep = 200;

// Creating new instance of the stepper class for every stepper motor
Stepper bm1(BigStep,46,47,48,49); // Arm A
Stepper bm2(BigStep,50,51,52,53); // Arm B
Stepper sm1(SmallStep,22,24,26,28); // Arm C
Stepper sm2(SmallStep,23,25,27,29); // Klo
Stepper sm3(SmallStep,30,31,32,33); // Rotation

void setup() {
  // Initializing arduino pins
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT);
  pinMode (JoyStick_X2, INPUT);
  pinMode (JoyStick_Y2, INPUT);
  pinMode (JoyStick_Z2, INPUT);
  digitalWrite(JoyStick_Z, HIGH);
  digitalWrite(JoyStick_Z2, HIGH);
  
  // Setting motor speed
  bm1.setSpeed(4);
  bm2.setSpeed(4);
  sm1.setSpeed(4);
  sm2.setSpeed(4);
  sm3.setSpeed(4);

  // Starting serial communication for debugging
  Serial.begin (9600); // 9600 bps
}

void loop() {
  // Initializing variables
  int x, y, z;
  int x2, y2, z2;
  
  // Reading joystick values
  x = analogRead (JoyStick_X) - 511 - x_fix;
  y = analogRead (JoyStick_Y) - 511 - y_fix;
  z = digitalRead (JoyStick_Z);
  x2 = analogRead (JoyStick_X2) - 511 - x2_fix;
  y2 = analogRead (JoyStick_Y2) - 511 - y2_fix;
  z2 = digitalRead (JoyStick_Z2);
  
  // Controlling robot arm based on joystick inputs 
  if (z == 0) {
    Serial.println("Z-på");
    // Öppna klo
    sm2.step(20);
  }
  
  if (x < -100) {
    Serial.print (x, DEC);Serial.println(" X-Ner");
    // Arm-A bakåt
    bm1.step(-1);
  }
  
  if (x > 100) {
    Serial.print (x, DEC);Serial.println(" X-Upp");
    // Arm-A framåt
    bm1.step(11);
  }
  
  if (y < -100) {
    Serial.print (y, DEC);Serial.println(" Y-Vänster");
    // Vänster rotation
    sm3.step(-20);
  }
  
  if (y > 100) {
    Serial.print (y, DEC);Serial.println(" Y-Höger");
    // Höger rotation
    sm3.step(20);
  }
  
  if (z2 == 0) {
    Serial.println("Z2-på");
    // Stäng klo
    sm2.step(-20);}
  
  if (x2 < -100) {
    Serial.print (x2, DEC);Serial.println(" X2-Ner");
    // Arm-B Ner
    bm2.step(-1); }
  
  if (x2 > 100) {
    Serial.print (x2, DEC);Serial.println(" X2-Upp");
    // Arm-B Upp
    bm2.step(1); }
  
  if (y2 < -100) {
    Serial.print (y2, DEC);Serial.println(" Y2-Vänster");
    // Arm-C Ner
    sm1.step(-20);}
  
  if (y2 > 100) {
    Serial.print (y2, DEC);Serial.println(" Y2-Höger");
    // Arm-C Upp
    sm1.step(20); }

}
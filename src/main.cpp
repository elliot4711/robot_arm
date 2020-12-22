#include <Arduino.h>
#include <Stepper.h> 

int numberofstep = 4096;
const int openPin = 12;
const int closePin = 8;

                                  
Stepper motor(numberofstep,9,11,10,6);    // we use pins 9, 11, 10, 6        
void setup() 
{ 
  motor.setSpeed(4); // we set motor speed at 9
  pinMode(openPin, INPUT);
  digitalWrite(openPin, HIGH);
  pinMode(closePin, INPUT);
  digitalWrite(closePin, HIGH);
}
void loop() 
{ 
  if (digitalRead(openPin) == LOW)
  {
    motor.step(20);
  }
  else if (digitalRead(closePin) == LOW)
  {
    motor.step(-20);
  }
  

}

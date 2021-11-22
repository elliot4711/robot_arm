# robot_arm
## Robotic project using an Arduino Mega, coded with C++, produced with electrical components and 3d-printed parts. Coded and produced with [@j-terp](https://github.com/j-terp)

### Note: Code is written using the Visual Studio Code "Platform IO" extension. To run the code on an Arduino only the source code itself (main.ccp located in the src folder) and the "Stepper.h" Arduino library are required. The other files are used by the PlatformIO extension. To run the code on an Arduino you can simply upload the source code using your preferred Arduino IDE.

This repository contains the Arduino code used to control a robot arm designed to pick up litter from the ground. The robot arm is controlled using two analog ps2 style joysticks and can move in five axes, including the claw opening and closing. This project uses two stepper motors of the NEMA 17 format and three 28byj-48 stepper motors. The NEMA 17 stepper motors are controlled using Adafruit TB6612 stepper motor drivers and the 28byj-48 motors are controlled using ULN2003 darlington arrays. This project uses an Arduino Mega due to the high amount of digital pins required to control the drivers, and by extenstion, the motors. If using another board with the Visual Studio Code extension, you will need to specify that you are using another board. 

This project requires very few screws, nuts and bolts and almost all parts can be 3D-printed. For STL files and assembly instructions see: https://www.thingiverse.com/thing:4847967

![alt text](gifntext-gif.gif "Logo Title Text 1")



### Electronic Mouse Trap
A 3D-printable mouse trap using an ultrasonic distance sesnsor and servo motor
## About this Project
This repo contains all of the files for my final project for my ECE1100: ECE Discovery Practicum class at Georgia Tech. Towards the begining of this semester, people across my dorm began spotting mice around the lounge and hallway areas. That gave me the idea to build a trap that would automatically detect when a mouse enters and close the door so that the mouse can't escape. I could then come back later and remove the mouse from the trap, and release it safely. The build uses an HC-SR04 ultrasonic sensor inside the trap to measure the distance to the closest object. Under normal conditions, this distance is constant, as the sensor is simply looking at a wall. When a mouse enters, the sensor detects that an object is close by. This causes the ESP-32 to send a command to a servo motor, which causes the door to fall. The entire system is powered off of a 9V battery
## Navigating this Repo
- **CAD** - Contains a STEP file for the assembly and a link to the Onshape document
- **Firmware** - Contains the firmware for the project
- **Electronics** - Contains the KiCAD files for this project
- **STLs** - Contains the three parts that need to be 3D printed
## Bill of Materials
|Part|Quantity|
|----|--------|
|MG996R Servo Motor|1|
|Breadboard|1-2|
|9V Battery|1|
|9V Battery Connector|1|
|ESP-32 Dev Board|1|
|HC-SR04 Ultrasonic Sensor|1|
|LM2596 Buck Convertor|1|
|1 kΩ Resistor|1|
|2 kΩ Resistor|1|
## Assembly
1. Print out the three files in the STLs folder of this repo
2. Use hot glue to mount the HC-SR04 Ultrasonic Sensor inside of the trap base
3. Assemble the electronics on the breadboard(s) accorrding to the schematic in Electronics/Schematic.pdf
4. Place the 9V battery in the holder, and use the connector to connect it to the rest of the circuit
5. Flash the ESP32 with the firmware found in the Firmware/Main folder of this repo
## Design Process
I used Onshape ([Link](https://cad.onshape.com/documents/e3882c1e08b8e152eea4bacc/w/22b5e1a3c5ab6f4c39ae26c9/e/5cbdab1673cd40ec0cd3e421?renderMode=0&uiState=6b00b90bbd30e9a9daed0efd)) to design the CAD model and KiCAD to plan out the electronics.

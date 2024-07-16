<div align="center">
  <h1>Cleaning Robot---CLEANOBOT_1.0</h1>
  <a href="https://sites.google.com/view/rhythmshah/cleanobot-1-0"><b>Visit my website</b></a>
</div>


## **Components Required :**

1. Arduino UNO
2. HC-05 Bluetooth Module
3.  5v 4 channel Relay Module
4.  5v Power Supply
5.  Ac appliances with connections of wires to relay module
6.  LED with 330 ohm resistor

## **Working-**

The CLEANOBOT 1.0 is a first-generation self-navigating cleaning robot designed for efficient cleaning, mopping, and sanitizing of designated areas. It incorporates two powerful 500-800 RPM DC gear motors capable of maintaining effective operation under load. Equipped with four ultrasonic sensors positioned in four directions, the robot detects obstacles to avoid collisions. Upon startup, the microcontroller verifies the absence of obstacles in the forward path; if clear, the robot moves forward while activating the water pump every 2 seconds to dispense cleaning solution. In the event of an obstacle, the robot evaluates both left and right directions, moving towards the direction with no obstruction or greater distance from obstacles beyond a predefined threshold of 6cm. If obstacles exist in both directions, it compares distances and turns towards the direction with a greater distance. If distances are equal or less than the threshold, it checks for obstacles in the backward direction, moving backward if clear or stopping if obstacles are detected within the threshold distance. Additionally, the robot features a water level indicator to signal when the cleaning solution container is full. Its detachable mop, washable upon removal from the robot, ensures thorough cleaning. The robot supports fast charging using a 12V 10A charger, with charging control switch functionality, enabling charging only when the robot is powered off. 

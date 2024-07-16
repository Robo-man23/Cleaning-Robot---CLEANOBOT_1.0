<div align="center">
  <h1>Cleaning Robot---CLEANOBOT_1.0</h1>
  <a href="https://sites.google.com/view/rhythmshah/cleanobot-1-0"><b>Visit my website</b></a>
</div>


## **Components Required :**

1. Geared dc motors x2
2. Raspberry Pi
3. Wheels x2
4. Li-ion batteries with battery holders x6
5. Motor driver- L298n/L293d
6. 5v Submersible pump
7. Ultrasonic sensors x4
8. Relay module 5v 1 channel
9. Drip infusion system (available in medical field)
10. Screws & nuts (3mm and 5mm)
11. Mounting brackets for Ultrasonic
12. Robot chasis (mdf board)
13. Detachable Мор
14. Water tube
15. Castor wheels x2
16. Connecting wires (single core wire + jumper wire)
17. Water level indicator
18.  Rocker switch, led, 300Ω resistors
19.  Funnel
20.  Zip ties

## **Working-**

The CLEANOBOT 1.0 is a first-generation self-navigating cleaning robot designed for efficient cleaning, mopping, and sanitizing of designated areas. It incorporates two powerful 500-800 RPM DC gear motors capable of maintaining effective operation under load. Equipped with four ultrasonic sensors positioned in four directions, the robot detects obstacles to avoid collisions. Upon startup, the microcontroller verifies the absence of obstacles in the forward path; if clear, the robot moves forward while activating the water pump every 2 seconds to dispense cleaning solution. In the event of an obstacle, the robot evaluates both left and right directions, moving towards the direction with no obstruction or greater distance from obstacles beyond a predefined threshold of 6cm. If obstacles exist in both directions, it compares distances and turns towards the direction with a greater distance. If distances are equal or less than the threshold, it checks for obstacles in the backward direction, moving backward if clear or stopping if obstacles are detected within the threshold distance. Additionally, the robot features a water level indicator to signal when the cleaning solution container is full. Its detachable mop, washable upon removal from the robot, ensures thorough cleaning. The robot supports fast charging using a 12V 10A charger, with charging control switch functionality, enabling charging only when the robot is powered off. 

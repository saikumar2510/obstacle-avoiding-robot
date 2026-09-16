# obstacle-avoiding-robot
an autonomous robot that detects obstacles in path and navigates around them without any human intervention
An Obstacle Avoiding Robot is an autonomous robotic vehicle that detects obstacles in its path and automatically changes direction to avoid collisions. This project uses an ultrasonic sensor to measure the distance between the robot and nearby objects.

📌 Features
Automatic obstacle detection
Collision avoidance
Autonomous movement
Ultrasonic distance measurement
Simple and low-cost hardware
Suitable for robotics and embedded-systems projects

🛠️ Components Required
Arduino Uno
Ultrasonic Sensor (HC-SR04)
L298N Motor Driver
2 × DC Gear Motors
Robot chassis
Robot wheels
Caster wheel
Battery
Jumper wires
Breadboard (optional)
🔌 Basic Connections

Component	Arduino
HC-SR04 Trig	Digital Pin 9
HC-SR04 Echo	Digital Pin 10
Motor Driver IN1	Digital Pin 2
Motor Driver IN2	Digital Pin 3
Motor Driver IN3	Digital Pin 4
Motor Driver IN4	Digital Pin 5
Motor Driver ENA	PWM Pin 6
Motor Driver ENB	PWM Pin 11
Connect the ultrasonic sensor's VCC to 5V and GND to Arduino GND.

Note: Motor-driver and motor wiring can vary depending on the particular L298N module and robot chassis.

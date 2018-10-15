# TotoTheRobot
![robot prototype](https://user-images.githubusercontent.com/41789916/46972631-3c12dc00-d0bf-11e8-85b6-8a37489c63ae.png)

# AN ARDUINO UNO PROTOTYPE
A prototype of an automatic moving robot operated by an Arduino
# THE CONCEPT
Create a simple robot, using the Arduino Uno to control it.
# THE COMPONENTS
The robot is controlled by the Arduino Uno, an electronic board designed for prototypes, which was programmed to manage all the other components. The movement is made possible by two 12V Servo Motors, piloted by a L298N Dual H-Bridge Motor Controller connected to the Arduino and powered by a 9V battery. An ultrasonic proximity sensor grants the robot the ability to avoid obstacles and a 2V red LED signals the state of the robot. All these components are mounted on a metallic frame, with tracks connected to the motors
# THE BEHAVIOR
Since the project had to be completed in a small amount of time, the behavior of the robot is pretty simple: when powered on, the robot boots up and starts scanning for obstacles in front of it. If nothing is detected, the LED turns on and the robot starts moving forward at maximum speed. As soon as an obstacle is detected, the motors are first stopped and then the left one starts spinning backwards at half speed for five seconds while the right one doesn’t move. In this way, the robot can move backward while slightly turning approximately 30 degrees to the right, so that he can avoid the obstacle. While in this state, the LED starts blinking, to signal the detection of the obstacle and the backward movement. After the end of this phase, if the obstacle isn’t in the detection range anymore, the robot returns in the forward moving state, otherwise multiple backward movement states are chained until the sensor stop detecting the obstacle.

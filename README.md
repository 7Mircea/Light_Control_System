# Light Control System
## Parts
- Arduino Uno
- LED
- Light Sensor
- Resistance 
## Implementation
The project control's automatically the light in the room using a one degree feedback loop with a 
PID regulator. The project uses an Arduino Uno for the logic part of the controler. The sensor 
reads the data, sends to the Arduino and this compares the actual level of light with the command.
The difference between the two, also known as error is multiplied with the proportional, derivative
and integral term. In this way we obtain the level of voltage to supply to the LED. The current through
the LED can be calculated as  I = \frac{U}{R} .
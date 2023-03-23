
# Arduino Car by Pedro Lorenzo Rosario

# My Mission



I absolutely adore programming, electronics, and robotics! There's something truly magical about being able to create and control machines, and I find it incredibly fulfilling to work with technology in this way. Whether I'm coding a new application or building a circuit,<br> I'm always eager to dive in and explore the possibilities. For me, there's nothing quite like the feeling of seeing my ideas come to life through programming and technology.

# Components Needed:


|        Component   Name       |Price                          |Purpose               |
|----------------|-------------------------------|-----------------------------|
|Arduino Uno (MicroController)|  9.99$ - 20.00$  |Is the brain of the Operation|
|L293D Motor Driver Module    | 13.00$           |its the main driver and power for the motors|
|battery Holder 4 cover slots |7.99$			       |to power Up the l293D and power up the Motor Wheels|
|ESP8266 Serial Wifi Module ESP-01 3.3V          |11.99$	| Wifi Module to control the car via Wifi|
|BreadBoard                   |7.77$	           |	Connect All the circuits to the components |


# How to use a L293D Motor Driver Shield

1. Pin 1 and Pin 9 are the enable pins for motor driver IC. Connect them to the positive supply voltage (+Vcc) through a 10K resistor.
2. Pin 16 is the ground (GND) pin, connect it to the negative supply voltage (GND).
3. Pins 2, 7, 10, and 15 are the input pins for the motor driver IC. Connect them to any digital output pins of your microcontroller or any other signal source.
4 .Pins 3, 6, 11, and 14 are the output pins for the motor driver IC. Connect them to the positive lead of the DC motor(s).
5 .Pins 4, 5, 12, and 13 are the ground pins for the motor driver IC. Connect them to the negative lead of the DC motor(s).
<br>
If you are using the L293D to drive a stepper motor, you will need to connect two pairs of output pins together to form an H-bridge configuration. This will allow the current to flow in either direction through the stepper motor.

Finally, connect the power supply voltage to the +Vcc and GND pins of the L293D.

### Some Diagrams to Understand the L293D Driver
<img src="https://2.bp.blogspot.com/-xWf_zFTGiHg/Vg2VVGX20LI/AAAAAAAAAz8/Gve48_08Xg0/s1600/Diagram_of_L293D.jpg"/>
<img src ="https://udvabony.com/wp-content/uploads/2019/05/L293D-V1-Motor-Driver-Shield-Connections.jpg"/>

## Heres the circuit that I made using TinkerCad
<img src="https://i.ibb.co/sgD89dp/Ingenious-Stantia-Albar.jpg"/>
<img src="https://i.ibb.co/VHT7nYY/Whats-App-Image-2023-03-22-at-10-48-41-PM.jpg"/>

<h2>My First Version Arduino Car V 0.1</h2>
<img width=600px heigth=700px src="https://i.ibb.co/Lvxdsfr/Whats-App-Image-2023-03-22-at-10-45-56-PM.jpg"/>

```cpp
// C++ code
//

int pinInput1 = 2;
int pinInput2 = 3;


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3,OUTPUT);

  
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}
```

# How to use the ESP8266 Wifi Module



# References


[How to connect wifi Module to the Arduino](https://www.deviceplus.com/arduino/how-to-connect-your-arduino-to-wi-fi/#:~:text=To%20hook%20everything%20up%2C%20connect%20these%20wires%3A%201,the%20ESP8266%20to%20GND%20on%20the%20Arduino%20Uno.)
<br>
[Lcd to diplay Battery Voltage](https://www.instructables.com/Displaying-Battery-Life-on-a-Liquid-Crystal-Displa/)


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

Perfect! I connected all wires to the board now we need to code it, I made a simple code that runs Forward, Reverse and Stop

```cpp
// C++ code
//

int pinInput2 = 2;
int pinInput3 = 3;
int pinInput4 = 4;
int pinInput5 = 5;


void setup()
{
  Serial.begin(9600);
  Serial.println("Type something!");
  pinMode(pinInput2, OUTPUT);
  pinMode(pinInput3,OUTPUT);
  pinMode(pinInput4, OUTPUT);
  pinMode(pinInput5,OUTPUT);
  
}

void loop()
{
  //Move Forward one wheel
  //digitalWrite(pinInput2, LOW);
  //digitalWrite(pinInput3, HIGH);
  
  //Move Forward two wheel
  //digitalWrite(pinInput4, LOW);
  //digitalWrite(pinInput5, HIGH);
  
  
   if(Serial.available()){
        int input = Serial.read();
        //Serial.print("You typed: " );
     
     if(input == 115){
       Serial.print("pressed S");
       digitalWrite(pinInput2, LOW);
       digitalWrite(pinInput3, LOW);
                    
       digitalWrite(pinInput4, LOW);
       digitalWrite(pinInput5, LOW);
       
     }
     
     else if(input == 98){
       Serial.print("Pressed B");
       
       digitalWrite(pinInput2, HIGH);
       digitalWrite(pinInput3, LOW);
                    
       digitalWrite(pinInput4, HIGH);
       digitalWrite(pinInput5, LOW);
       
     }
     
     else if(input == 102){
       Serial.print("Pressed F");
       
       digitalWrite(pinInput2, LOW);
       digitalWrite(pinInput3, HIGH);
                    
       digitalWrite(pinInput4, LOW);
       digitalWrite(pinInput5, HIGH);
     }
    }
}

```

# Problem #1
As is stated on the law of Murphy Anything that can go wrong will go wrong. 
<br>
It worked fine the motor turned on, it went forward and in reverse. The only problem is that it only turned 1 motor no both.

1. The wires may be loose or not connected properly 
2. The battery does not have enough voltage to spin both wheels

3. Theres something wrong in the code

[Video of my Arduino Car V 0.1](https://youtube.com/shorts/DFwtnSy7x_s?feature=share)

## ----------------------------------
ITS ALIVEE!!!, now both wheels spin, the only change I did was taking out the 9v Battery for external power,
it Works with the 5V of the arduino but it runs at a lower RPM, I Hope this does not blow up in my face.
## Solucion to problem #1
## ----------------------------------

Solved problem #, the reason only 1 motor was spinning it was an error in the code,I put the number of the wrong pin in the arduino, so it wasen't enabiling the second motor 
<br><br>

Heres the Code with the IR Reciever

```cpp

//Define input and PWM pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENA 9
#define ENB 10
#include <IRremote.h>

#define IRReceiver 11


void setup() {
//Set those pins as output pins
 IrReceiver.begin(IRReceiver);
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IRReceiver, INPUT);
}

void loop() {

 if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    switch(command){
      case 12:
      forward();
      break;

      case 22:
      Stop();
      break;

      case 24:
      backward();
    }
    }
}

void forward() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void backward() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}



```


[Video of my Arduino Car V 0.2](https://youtube.com/shorts/fG3_x3Uz1w8?feature=share)

#### I made some changes to the body, is still a work in progress
<img src="https://i.ibb.co/P13B9Wg/3049eb3f-442e-4156-aa34-0a1a4927044f.jpg"/>
<img src="https://i.ibb.co/8z0Cyzx/3fa43499-5a2a-48b7-a3fb-8a60c352b654.jpg"/>



# How to use the ESP8266 Wifi Module



# References


[How to connect wifi Module to the Arduino](https://www.deviceplus.com/arduino/how-to-connect-your-arduino-to-wi-fi/#:~:text=To%20hook%20everything%20up%2C%20connect%20these%20wires%3A%201,the%20ESP8266%20to%20GND%20on%20the%20Arduino%20Uno.)
<br>
[How to use a L293D](https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/)
<br>
[Lcd to diplay Battery Voltage](https://www.instructables.com/Displaying-Battery-Life-on-a-Liquid-Crystal-Displa/)

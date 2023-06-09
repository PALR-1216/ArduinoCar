
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
      break;

      case 8:
      TurnLeft();
      break;

      case 28:
      TurnRight();
      break;
    }
    }
}

void forward() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
//second motor is moving in diferent direction Dont know why
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void backward() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
//same here motor is moving in diferent direction 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}



void TurnLeft() {

	analogWrite(ENB,255);
	analogWrite(ENA,255);

	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);

	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
}


void TurnRight() {
  analogWrite(ENB,255);
	analogWrite(ENA,255);

	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);   
  digitalWrite(IN4, LOW);  




}

void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

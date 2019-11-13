#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

//Select which 'port' M1, M2, M3, or M4. In this case, grab all 4 motor ports.
Adafruit_DCMotor *myMotorFR = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorFL = AFMS.getMotor(2);
Adafruit_DCMotor *myMotorLR = AFMS.getMotor(3);
Adafruit_DCMotor *myMotorRR = AFMS.getMotor(4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // set up Serial Library at 9600 bps
  Serial.println("Adafruit Motoshield v2 - DC Motor startup.");

  AFMS.begin(); //create with the default frequency 1.6KHz
                //or use alt frequency, say 1KHz, AFMS.begin(1000);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotorFR->setSpeed(100);
  myMotorFL->setSpeed(100);
  myMotorLR->setSpeed(100);
  myMotorRR->setSpeed(100);

  //run motor direction
  myMotorFR->run(FORWARD);
  myMotorFL->run(FORWARD);
  myMotorLR->run(FORWARD);
  myMotorRR->run(FORWARD);

  //sleep for 5s
  delay(5000);

  // turn off motor
  myMotorFR->run(RELEASE);
  myMotorFL->run(RELEASE);
  myMotorLR->run(RELEASE);
  myMotorRR->run(RELEASE);

}

void loop() {
  // put your main code here, to run repeatedly:

}

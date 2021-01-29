#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 13, 4, 0, 2, 14);

// Pins
const int trigP = 5;
const int echoP = 16;
const int lightControl = 15;
const int pumpControl = 9;

// Results from sensors
long duration;
int distance;
int lightIntensity;

void setup() {

  

//  // UltraSonic
  pinMode(trigP,OUTPUT);
  pinMode(echoP,INPUT);

  pinMode(lightControl,OUTPUT);
  //pinMode(pumpControl,OUTPUT);

//  // LED
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);

}

void loop() {

  // UltraSonic start
  digitalWrite(trigP,LOW);
  delayMicroseconds(2);
  digitalWrite(trigP,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP,LOW);

  duration = pulseIn(echoP,HIGH);
  distance = duration*0.034/2;                
  // ultrasonic end-

  // LDR
  lightIntensity = (int) analogRead(A0);
  Serial.println(lightIntensity);
  Serial.println(distance);
  // LDR

  // LCD
  
  lcd.setCursor(0,0);
  lcd.print(distance);

  lcd.setCursor(0,1);
  lcd.print(lightIntensity);
  //LCD

//  // Relay Control

  // Light and Pump

  digitalWrite(lightControl,HIGH);
  delay(5000);

  digitalWrite(lightControl,LOW);
  delay(5000);

  
  lcd.clear();
  
}

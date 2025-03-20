
#include <LiquidCrystal.h> 
LiquidCrystal LCD(11,10,9,2,3,4,5); 

#define trigPin 13
#define echoPin 12 


void setup() 
{  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  LCD.begin(16,2); 
  LCD.setCursor(0,0); 
  LCD.print("Target Distance:"); 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  LCD.setCursor(0,1);  
  LCD.print("                ");
  LCD.setCursor(0,1);   
  LCD.print(distance);
  LCD.print(" cm"); 
  delay(250);
}

int trigPin = 6; /* trig pini 6  */
int echoPin = 7;  /* echo pini 7 */
const int buzzer = 5;
#include <Servo.h>

Servo cnnServo;
Servo radarServo;

long sure;
long uzaklik;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); 
cnnServo.attach(8);
radarServo.attach(9);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  sure = pulseIn(echoPin, HIGH); 
  uzaklik= sure /29.1/2; 
            
  if(uzaklik > 200){
    uzaklik = 200;
    }
    
    Serial.print("Uzaklik ");  
  Serial.print(uzaklik); 
  delay(100);
  
     for(int i=165;i>15;i--){  
  radarServo.write(i);
  delay(30);
  
  if(uzaklik <199){
    cnnServo.write(i);
    
    }
  }

}

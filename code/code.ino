  int pinMovement=13;
  

  int echoPin = 2; // Echo Pin of Ultrasonic Sensor
  int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
  
void setup() {
  pinMode(pinMovement ,INPUT);
   pinMode(echoPin, INPUT); // initialising pin 2 as input
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
 
  Serial.begin(9600);
}
void loop() {
   int value = digitalRead(pinMovement);  // read input value
  if (value == HIGH) {            // check if the input is HIGH
      Serial.print("open");
  } else {
      Serial.print("close");
  }
  Serial.println();
  
    long duration, inches, cm;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  cm = microsecondsToCentimeters(duration); // calling method
  if (cm<=15){
    Serial.print("close");
    }else {
      Serial.print("open");
    }
   Serial.println();
   
   delay(100);
}
long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}

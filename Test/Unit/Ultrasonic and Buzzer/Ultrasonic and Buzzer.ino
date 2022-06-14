const int trigPin = 13;
int echoPin = 12;


void setup() {
Serial.begin(9600);
pinMode(8,OUTPUT);
}

void loop()
{
long duration;
int cm;

pinMode(trigPin, OUTPUT);


digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
cm =  duration * 0.034 / 2;
Serial.print("Distance : ");
Serial.print(cm);
Serial.print(" cm");
Serial.println();
delay(100);
 if(cm <= 10) 
  {
    tone(8, 300,100);
  }
  else 
  {
    
  }
}


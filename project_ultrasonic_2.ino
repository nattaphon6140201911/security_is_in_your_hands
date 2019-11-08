#define trigPin PIN_PB0

#define echoPin PIN_PB1

#define led PIN_PC0

#define buzzer PIN_PC1

#define ldrPin PIN_PC2

void setup()

{ Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(led, OUTPUT);

pinMode(buzzer, OUTPUT);

pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input

}

void loop()

{ long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

int ldrStatus = analogRead(ldrPin);



if ((distance < 20) and (ldrStatus <=300))

{ digitalWrite(led,HIGH);
  
  delay(10000);
}

else {

digitalWrite(led,LOW);

}



if (distance < 19){

  digitalWrite(buzzer,HIGH);
  delay(3000);
}

else {

digitalWrite(buzzer,LOW);
}


Serial.print(distance);

Serial.println(" cm");

delay(500);

}

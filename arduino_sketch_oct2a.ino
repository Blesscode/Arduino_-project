//Measure the distance to an object using the ultrasonic sensor and turn on the LED if the object is within a certain range

/*Ardunio board used= ARDUINO UNO R3
sensor used= HC-SRO4
connecting wires */

/* *NOTE*:Here I have used the primary board light present on the board itself*/
//code:

int ledPin=13;         //set your led pin
int trigPin= 9;       //set your trig pin from the sensor
int ecoPin=10;       //set your eco pin from the sensor
float speed=0.0343;


//int ledState=LOW;
long time;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(ecoPin,INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //make shure trig pin is low at bigining for fresh start
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  //turn down the trig pin an wait for eco pin
  digitalWrite(trigPin,LOW);

  //record the value for eco pin amd store it in distance
  time=pulseIn(ecoPin,HIGH);

  //calculating distance using formula
  //here divide by 2 is to deduct the return back duration 
  distance=speed*time/2;

  if(distance<20){            //define your range here
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}
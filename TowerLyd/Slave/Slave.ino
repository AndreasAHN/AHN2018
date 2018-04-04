



 unsigned long afstand();



const int echoPin=  12;
const int trigPin= 11;
const int VCC1_= 10;
const int VCC2_= 4;
const int tx= 3;
#define rx A0


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(VCC1_, OUTPUT);
  pinMode(VCC2_, OUTPUT);
  pinMode(tx, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(VCC1_, HIGH);
   digitalWrite(VCC2_, HIGH);

   while(1)
   {
      digitalWrite(trigPin, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin, HIGH);

   }
 /* while(1)
  {
    if(analogRead(rx) > 750)
    {
      digitalWrite(trigPin,HIGH);
      Serial.print("JEG SENDER MOHAHAHA");
    }
    else
    {
      digitalWrite(trigPin, LOW);
    }
    
    Serial.print(analogRead(rx));
    Serial.print("\r \n");
  }*/
}




 unsigned long afstand()
  {
    unsigned int distanceAvg = 0;
    
    for( unsigned int a = 0; a < 10; a = a + 1 )
    {
      
      long duration, distance;
      digitalWrite(tx, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;

      distanceAvg = distanceAvg + distance;
    }
    

    return distanceAvg/10;
  }

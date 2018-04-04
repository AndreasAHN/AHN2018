



 unsigned long afstand();



const int echoPin = 13;
const int trigPin = 12;
const int VCC1_ = 11;
const int VCC2_ = 53;
const int tx = 51;
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
  digitalWrite(VCC1_ , HIGH);
  digitalWrite(VCC2_ , HIGH);
   
   while(1)
   { 
      Serial.print("\n Afstanden er:");
      Serial.print(afstand());
      delay(1000);
   }
}




 unsigned long afstand()
  {
    unsigned int distanceAvg = 0;
    
   
      
      long duration, distance;
      digitalWrite(trigPin, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;

      distanceAvg = distanceAvg + distance;
    
    

    return distanceAvg;
  }

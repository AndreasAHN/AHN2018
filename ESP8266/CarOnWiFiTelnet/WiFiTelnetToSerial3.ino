
/*
  Autor Andreas Hervert Nielsen
  Date 25/10-2017 - kl 15:00
  
  Emne: Til ESP8266, for benyttelse til master for nano slaven og hovedekontrol af bilen.
          Masterens job: er at styre alle bilens funktioner og kommunikere til tilsluttede moduler. 
 */
 
#include <ESP8266WiFi.h>








void runForward(int modee,int turns, int speedo);
void runBackward(int modee,int turns, int speedo);
void turnLeft(int modee,int turns, int speedo);
void turnRight(int modee,int turns, int speedo);








unsigned long distance1_();







// Number of cycles from external counter needed to generate a signal event
#define CYCLES_PER_SIGNAL 5000

// Base tone frequency (speaker)
#define BASE_TONE_FREQUENCY 280

// Frequency delta threshold for fancy spinner to trigger
#define SPINNER_THRESHOLD 700

// Pin definitions
#define SENSITIVITY_POT_APIN 0

unsigned long lastSignalTime = 0;
unsigned long signalTimeDelta = 0;

boolean firstSignal = true;
unsigned long storedTimeDelta = 0;

// This signal is called whenever OCR1A reaches 0
// (Note: OCR1A is decremented on every external clock cycle)
SIGNAL(TIMER1_COMPA_vect)
{
  unsigned long currentTime = micros();
  signalTimeDelta =  currentTime - lastSignalTime;
  lastSignalTime = currentTime;

  if (firstSignal)
  {
    firstSignal = false;
  }
  else if (storedTimeDelta == 0)
  {
    storedTimeDelta = signalTimeDelta;
  }

  // Reset OCR1A
  OCR1A += CYCLES_PER_SIGNAL;
}






//how many clients should be able to telnet to this ESP8266
#define MAX_SRV_CLIENTS 1
const char* ssid = "";
const char* password = "";

WiFiServer server(23);
WiFiClient serverClients[MAX_SRV_CLIENTS];






uint8_t message;
int hastighed = 20;
int firstStart = 0;

const int alert = 9; //Buzzer


const int trigPin1_ = 3;//Ultralyd  
const int echoPin1_ = 1;//Ultralyd


const int A1_ = 15; //Stepper1
const int A2_ = 13; //Stepper1
const int A3_ = 2; //Stepper2
const int A4_ = 0; //Stepper2


const int B1_ = 12; //Stepper1
const int B2_ = 14; //Stepper1
const int B3_ = 4; //Stepper2
const int B4_ = 5; //Stepper2

const int lys = 10; //Lys


int speedo = 800;
int modee = 0;
int turns = 200;





void setup() {

  // Set WGM(Waveform Generation Mode) to 0 (Normal)
  TCCR1A = 0b00000000;
  
  // Set CSS(Clock Speed Selection) to 0b111 (External clock source on T0 pin
  // (ie, pin 5 on UNO). Clock on rising edge.)
  TCCR1B = 0b00000111;

  // Enable timer compare interrupt A (ie, SIGNAL(TIMER1_COMPA_VECT))
  TIMSK1 |= (1 << OCIE1A);

  // Set OCR1A (timer A counter) to 1 to trigger interrupt on next cycle
  OCR1A = 1;

  ESP.wdtDisable();
  ESP.wdtEnable(WDTO_8S);


  pinMode(trigPin1_, OUTPUT);
  pinMode(echoPin1_, INPUT);
  
 // pinMode(alert, OUTPUT);
  //  pinMode(lys, OUTPUT);

  pinMode(A1_, OUTPUT);
  pinMode(A2_, OUTPUT);
 // pinMode(A3_, OUTPUT);
  pinMode(A4_, OUTPUT);
  pinMode(B1_, OUTPUT);
  pinMode(B2_, OUTPUT);
  pinMode(B3_, OUTPUT);
  pinMode(B4_, OUTPUT);
  
  Serial1.begin(9600);
  WiFi.begin(ssid, password);
  Serial1.print("\nConnecting to "); Serial1.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial1.print("Could not connect to"); Serial1.println(ssid);
    while(1) delay(500);
  }
  //start UART and the server
  Serial.begin(115200);
  server.begin();
  server.setNoDelay(true);
  
  Serial1.print("Ready! Use 'telnet ");
  Serial1.print(WiFi.localIP());
  Serial1.println(" 23' to connect");
}

void loop() {
  ESP.wdtFeed();

  uint8_t i;
  //check if there are any new clients
  if (server.hasClient()){
    for(i = 0; i < MAX_SRV_CLIENTS; i++){
      //find free/disconnected spot
      if (!serverClients[i] || !serverClients[i].connected()){
        if(serverClients[i]) serverClients[i].stop();
        serverClients[i] = server.available();
        Serial1.print("New client: "); Serial1.print(i);
        continue;
      }
    }
    //no free/disconnected spot so reject
    WiFiClient serverClient = server.available();
    serverClient.stop();
  }


   if (firstStart == 0)
  {
              //Udskriv ip addresse
          Serial.print ( "Connected to " );
          Serial.println ( ssid );
          Serial.print ( "IP address: " );
          Serial.println ( WiFi.localIP() );
      firstStart = 1;
  }


  
  //check clients for data
  for(i = 0; i < MAX_SRV_CLIENTS; i++){
    if (serverClients[i] && serverClients[i].connected()){
      if(serverClients[i].available()){
        //get data from the telnet client and push it to the UART, AHN save all data to buffer message
        //while(serverClients[i].available()) Serial.write(message = serverClients[i].read()); 
        message = serverClients[i].read();
        Serial.print("Modtaget besked : ");
        Serial.print(message);
        Serial.print("\n");
      }
    }
  }



   
  //Modtager besked
 // message = serverClients[1].read();
  digitalWrite(alert, LOW);
  //check UART for data
  
  if(Serial.available()){
    size_t len = Serial.available();
    uint8_t sbuf[len];
    Serial.readBytes(sbuf, len);
    //push UART data to all connected telnet clients
    for(i = 0; i < MAX_SRV_CLIENTS; i++){
      if (serverClients[i] && serverClients[i].connected()){
        serverClients[i].write(sbuf, len);
        delay(hastighed);
      }
    }
  }
  
  

  
  if( message == 119) //frem w
  {
      serverClients[0].write("Fremad \n");
      runForward(modee,turns, speedo);
  }
else if( message == 115) //tilbage s
  {
    serverClients[0].write("Tilbage \n");
      runBackward(modee,turns, speedo);
  }
  else if( message == 97) //venstre a
  {
    serverClients[0].write("Left \n");
      turnLeft(modee,turns, speedo);
  }
  else if( message == 100) //højre d
  {
    serverClients[0].write("Right \n");
      turnRight(modee,turns, speedo);
  }
    else if( message == 113)  //k venstre q
  {
    serverClients[0].write("Half step \n");
      modee = 0;
  }
      else if( message == 101)  //k højre e
  {
    serverClients[0].write("Fuldstep \n");
      modee = 1;
  }
  else if( message == 49)    // fart op 1
  {
    serverClients[0].write("Fart op: ");
      speedo = speedo + 100;
      serverClients[0].write("\n");
  }
else if( message == 50) //fart ned 2
  {
    serverClients[0].write("Fart ned: ");
      speedo = speedo - 100;
      serverClients[0].write("\n");
  }
  else if( message == 51) //DYT 51
  {
    serverClients[0].write("DYT \n");
      digitalWrite(alert, HIGH);
      delay(1000);
      digitalWrite(alert, LOW);
  }
  else if( message == 'r') //DYT 51
  {
      digitalWrite(alert, HIGH);
      digitalWrite(lys, HIGH);
      delay(1000);
      digitalWrite(alert, LOW);
      digitalWrite(lys, LOW);
  }





    float sensitivity = mapFloat(analogRead(SENSITIVITY_POT_APIN), 0, 1023, 0.5, 10.0);
    int storedTimeDeltaDifference = (storedTimeDelta - signalTimeDelta) * sensitivity;
    tone(SPEAKER_PIN, BASE_TONE_FREQUENCY + storedTimeDeltaDifference);

    if (storedTimeDeltaDifference > SPINNER_THRESHOLD)
    {
      
      serverClients[0].write("METAL \n");
    }
    else
    {
      serverClients[0].write("No_METAL \n");
    }


  


  
}



unsigned long distance1_()
  {
    unsigned int distanceAvg = 0;
    
    for( unsigned int a = 0; a < 10; a = a + 1 )
    {
      
    long duration, distance;
    digitalWrite(trigPin1_, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin1_, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin1_, LOW);
    duration = pulseIn(echoPin1_, HIGH);
    distance = (duration/2) / 29.1;

    distanceAvg = distanceAvg + distance;
    }
      

    return distanceAvg/10;
  }




void runForward(int modee,int turns, int speedo)
{
    if( modee == 0)
    {
        for(int x = 0; x < turns; x = x + 1)
        {
                            //Step 1
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
                                        
                            //Step 2
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
                                        
                            //Step 3
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
                                       
                            //Step 4
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                            
                            //Step 5
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, LOW);        
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                            
                            //Step 6
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                            //Step 7
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                            //Step 8
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);

        }
    }
    else
    {
        for(int x = 0; x < turns; x = x + 1)
        {
                            //Step 1
                            
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
                                        
                            //Step 2
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            
                            delayMicroseconds(speedo);
                                        
                            //Step 3
                           
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
                                       
                            //Step 4
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            
                            delayMicroseconds(speedo);
                            
                            //Step 5
                                  
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                            
                            //Step 6
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                           
                            delayMicroseconds(speedo);
                                        
                            //Step 7
                            
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                            //Step 8
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            delayMicroseconds(speedo);
        }
    }
    
    //Reset mod kortslutning
                    digitalWrite(A1_, LOW);
                    digitalWrite(A2_, LOW);
                    digitalWrite(B1_, LOW);
                    digitalWrite(B2_, LOW);
                    //Reset mod kortslutning
                    digitalWrite(A3_, LOW);
                    digitalWrite(A4_, LOW);
                    digitalWrite(B3_, LOW);
                    digitalWrite(B4_, LOW);
   
 }
/* [] END OF FILE */


void runBackward(int modee,int turns, int speedo)
{
   
    if( modee == 0)
    {
        for(int x = turns; x >= 0; x = x - 1)
        {
                            //Step 8
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                            //Step 7
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                          //Step 6
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                       
                           
                            
                            //Step 5
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, LOW);        
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                            
                             //Step 4
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                              //Step 3
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
              
              //Step 2
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
                                        
                            
              
              //Step 1
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, LOW);
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
        }
    }
    else
    {
        for(int x = turns; x >= 0; x = x - 1)
        {
                            //Step 8
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            
                            delayMicroseconds(speedo);
                                        
                            //Step 7
                         
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                                        
                          //Step 6
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, LOW);
                            digitalWrite(B2_, HIGH);
                            
                            delayMicroseconds(speedo);
                                       
                           
                            
                            //Step 5
                             
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, HIGH);
                            digitalWrite(B4_, LOW);
                            delayMicroseconds(speedo);
                            
                             //Step 4
                            digitalWrite(A1_, LOW);
                            digitalWrite(A2_, HIGH);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                           
                            delayMicroseconds(speedo);
                                        
                              //Step 3
                           
                            digitalWrite(A3_, LOW);
                            digitalWrite(A4_, HIGH);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
              
              //Step 2
                            digitalWrite(A1_, HIGH);
                            digitalWrite(A2_, LOW);
                            digitalWrite(B1_, HIGH);
                            digitalWrite(B2_, LOW);
                            
                            delayMicroseconds(speedo);
                                        
                            
              
              //Step 1
                           
                            digitalWrite(A3_, HIGH);
                            digitalWrite(A4_, LOW);
                            digitalWrite(B3_, LOW);
                            digitalWrite(B4_, HIGH);
                            delayMicroseconds(speedo);
        
        }
    }
        //Reset mod kortslutning
                    digitalWrite(A1_, LOW);
                    digitalWrite(A2_, LOW);
                    digitalWrite(B1_, LOW);
                    digitalWrite(B2_, LOW);
                    //Reset mod kortslutning
                    digitalWrite(A3_, LOW);
                    digitalWrite(A4_, LOW);
                    digitalWrite(B3_, LOW);
                    digitalWrite(B4_, LOW);
 }

void turnLeft(int modee,int turns, int speedo)
{ 
     if( modee == 0)
    {
            for(int x = 0; x < turns; x = x + 1)
            {
                                //Step 1
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                            
                                //Step 2
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                            
                                //Step 3
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                           
                                //Step 4
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                
                                //Step 5
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, LOW);        
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                
                                //Step 6
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);
                                            
                                //Step 7
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);
                                            
                                //Step 8
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);       
            }
        }
        else
        {
            for(int x = 0; x < turns; x = x + 1)
            {
                                                                           
                                //Step 2
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                            
                               
                                           
                                //Step 4
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                
                             
                                
                                //Step 6
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);
                               
                                            
                                //Step 8
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);        
        }
    }
        //Reset mod kortslutning
                    digitalWrite(A1_, LOW);
                    digitalWrite(A2_, LOW);
                    digitalWrite(B1_, LOW);
                    digitalWrite(B2_, LOW);
                    //Reset mod kortslutning
                    digitalWrite(A3_, LOW);
                    digitalWrite(A4_, LOW);
                    digitalWrite(B3_, LOW);
                    digitalWrite(B4_, LOW);
 }


void turnRight(int modee,int turns, int speedo)
{  
   
     if( modee == 0)
    {
             for(int x = turns; x >= 0; x = x - 1)
            {
                                //Step 1
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                            
                                //Step 2
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                            
                                //Step 3
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                           
                                //Step 4
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                
                                //Step 5
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, LOW);        
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                
                                //Step 6
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);
                                            
                                //Step 7
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);
                                            
                                //Step 8
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);       
            }
        }
        else
        {
             for(int x = turns; x >= 0; x = x - 1)
            {
                                                                           
                                //Step 2
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                            
                               
                                           
                                //Step 4
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, HIGH);
                                digitalWrite(B2_, LOW);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, HIGH);
                                digitalWrite(B4_, LOW);
                                delayMicroseconds(speedo);
                                
                             
                                
                                //Step 6
                                digitalWrite(A1_, LOW);
                                digitalWrite(A2_, HIGH);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, LOW);
                                digitalWrite(A4_, HIGH);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);
                               
                                            
                                //Step 8
                                digitalWrite(A1_, HIGH);
                                digitalWrite(A2_, LOW);
                                digitalWrite(B1_, LOW);
                                digitalWrite(B2_, HIGH);
                                digitalWrite(A3_, HIGH);
                                digitalWrite(A4_, LOW);
                                digitalWrite(B3_, LOW);
                                digitalWrite(B4_, HIGH);
                                delayMicroseconds(speedo);   
            }
        }
        //Reset mod kortslutning
                    digitalWrite(A1_, LOW);
                    digitalWrite(A2_, LOW);
                    digitalWrite(B1_, LOW);
                    digitalWrite(B2_, LOW);
                    //Reset mod kortslutning
                    digitalWrite(A3_, LOW);
                    digitalWrite(A4_, LOW);
                    digitalWrite(B3_, LOW);
                    digitalWrite(B4_, LOW);
 }



float mapFloat(int input, int inMin, int inMax, float outMin, float outMax)
{
  float scale = (float)(input - inMin) / (inMax - inMin);
  return ((outMax - outMin) * scale) + outMin;
}


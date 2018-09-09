
//Libs
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <DHT.h>

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value


void setup() 
{
    Serial.begin(9600);
    //Wire.begin();
}


  
void loop() 
{
     while(true)
     {
        delay(100);
        //Read data and store it to variables hum and temp
        hum = dht.readHumidity();
        temp= dht.readTemperature();
        //Print temp and humidity values to serial monitor
        Serial.print("Humidity: ");
        Serial.print(hum);
        Serial.print(" %, Temp: ");
        Serial.print(temp);
        Serial.println(" Celsius");
        delay(100); 
        
        Adafruit_SSD1306 display(-1);
        display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.clearDisplay();
        display.print("Humidity: ");
        display.print(hum);
        display.println(" %"); 
        display.print("Temp: ");
        display.print(temp);
        display.println(" Celsius");

        display.display();
        
        
     }
}








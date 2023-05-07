/*********************

Example code for the Adafruit RGB Character LCD Shield and Library

This code displays text on the shield, and also reads the buttons on the keypad.
When a button is pressed, the backlight changes color.

**********************/

// Libraries for the Adafruit RGB/LCD Shield
#include <Wire.h>
//#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>


// Libraries for the DS18B20 Temperature Sensor
#include <OneWire.h>
#include <DallasTemperature.h>

// ************************************************
// Pin definitions
// ************************************************

// One-Wire Temperature Sensor
// (Use GPIO pins for power/ground to simplify the wiring)
#define ONE_WIRE_BUS 2
#define ONE_WIRE_PWR 3
#define ONE_WIRE_GND 4
#define PIN_BUZZER 9
#define PIN_LED 13

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
//#define RED 0x1
//#define YELLOW 0x3
//#define GREEN 0x2
//#define TEAL 0x6
//#define BLUE 0x4
//#define VIOLET 0x5
#define WHITE 0x7
#define CHAUFFE 1
#define REFROIDIT 0
#define TEMP_CHAUFFE 80
#define TEMP_REFROIDIT 56
#define OFFSET 2 // Surestimation de la temperature par la sonde par rapport a mon thermometre

//unsigned long lastInput = 0; // last button press

byte degree[8] = // define the degree symbol 
{ 
 B00110, 
 B01001, 
 B01001, 
 B00110, 
 B00000,
 B00000, 
 B00000, 
 B00000 
}; 

const int logInterval = 10000; // log every 10 seconds
long lastLogTime = 0;
double temperature;
int etat = REFROIDIT;
uint8_t buttons; // variable qui dira si on a presé un bouton

// ************************************************
// Sensor Variables and constants
// Data wire is plugged into port 2 on the Arduino

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress tempSensor;


void setup() {
  int time = millis();
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT); 

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

     // Set up Ground & Power for the sensor from GPIO pins
   pinMode(ONE_WIRE_GND, OUTPUT);
   digitalWrite(ONE_WIRE_GND, LOW);
   pinMode(ONE_WIRE_PWR, OUTPUT);
   digitalWrite(ONE_WIRE_PWR, HIGH);  
   
   // Initialize LCD DiSplay 
   lcd.begin(16, 2);
   lcd.createChar(1, degree); // create degree symbol from the binary
   lcd.setBacklight(WHITE);

//    lcd.print("Haut : pates    ");
//    lcd.print("Bas : Yaourt    ");
    
    
   lcd.print("Yaourt chauffe  ");

   // Start up the DS18B20 One Wire Temperature Sensor
   sensors.begin();
   if (!sensors.getAddress(tempSensor, 0)) 
   {
      lcd.setCursor(0, 1);
      lcd.print(F("Sensor Error"));
   }
   sensors.setResolution(tempSensor, 12);
   sensors.setWaitForConversion(false);
   sensors.requestTemperatures(); // Dit au senseur de mesurer la temérature
   delay(100);
  //  Serial.begin(9600);
}

void loop() {
    temperature = sensors.getTempC(tempSensor) + OFFSET;
    // Serial.println(temperature);
    sensors.requestTemperatures(); // prime the pump for the next one - but don't wait

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    if (etat==CHAUFFE)
    {
       lcd.print("Yaourt chauffe  ");
    }
    else
    {
       lcd.print("Yaourt refroidit");
    }
    lcd.setCursor(0, 1);
    lcd.print("T = ");
    lcd.print(temperature);
    lcd.write(1);
    lcd.print(F("C"));
 
    buttons = lcd.readButtons();
    if (buttons) {
       etat = 1-etat; // passer du chauffage au refroidissement, ou vice-versa
       digitalWrite(9, LOW);  // Arrêter le buzzer 
    }
  
  // on controle la temperature et si necessaire on sonne
    if (((etat==CHAUFFE) && (temperature > TEMP_CHAUFFE)) || ((etat==REFROIDIT) && (temperature < TEMP_REFROIDIT)))
    {
      digitalWrite(PIN_LED, HIGH);
      digitalWrite(PIN_BUZZER, HIGH);
      delay(250);
      digitalWrite(PIN_LED, LOW); 
      digitalWrite(PIN_BUZZER, LOW); 
    }
    delay(250); // On mesure toutes les secondes
}

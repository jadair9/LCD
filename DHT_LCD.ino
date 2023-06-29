#include "DHT.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTPIN 7 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
Serial.println(F("DHT11 test!"));
dht.begin();
lcd.begin(16, 2); //lcd.begin(columns, rows); set up the dimension of LCD displayer
}
void loop() {
// Wait a few seconds between measurements.
delay(2000);
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity();
// Read temperature as Celsius (the default)
float t = dht.readTemperature();
// Read temperature as Fahrenheit (isFahrenheit = true)
// if there is any error, serial monitor would print: 
if (isnan(h) || isnan(t)) {
Serial.println(F("Failed to read from DHT sensor!"));
return;
}
//lcd setup
lcd.setCursor(0,0); 
lcd.print("Temp: ");
lcd.print(t);
lcd.print((char)223); //use this for the symbol for degree º 
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Humidity: ");
lcd.print(h);
lcd.print("%");
delay(1000);
}

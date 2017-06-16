/**
 * This code includes usage of DHT11 on Arduino Uno.
 * Wiring diagram of DHT11 = http://www.hobbyist.co.nz/sites/default/files/Arduino_Sensor_interface.png
 * Library source of DHT11 = https://github.com/adafruit/DHT-sensor-library
 * 
 * @author Çağatay Tanyıldız
 * @email  cagataytanyildiz[at]protonmail[dot]com
*/
#include "DHT.h"        
#define DHT_PIN A0
#define DHT_TYPE DHT11 //Specify sensor type 

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidity test!");
  Serial.println("T(C) \tH(%)");
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); 
  
  Serial.println("Sensor is working");
  Serial.println(String(temperature)+" | "+String(humidity));
  delay(5000);
}

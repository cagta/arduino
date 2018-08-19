/**
 * This code includes usage of MQ6 on Arduino Uno.
 * Wiring diagram of MQ6 = http://2.bp.blogspot.com/-1j6hyWiunwo/VPM9FQ-P7wI/AAAAAAAAAV8/mSQUrWlhSqw/s1600/mq-6.jpg
 *
 * NOTE: MQ6 needs a 5V heater, in this project I use it from Arduino.
 * But I advise you to use outer heater.
 * 
 * NOTE: Even if there is no connection between MQ6 and Arduino, you can see some results 
 * on serial monitor. You need to be sure of it's source. Don't forget to test MQ6 with some
 * gas source. It can even be your breath. 
 * 
 * @author Cagatay Tanyildiz
 * @email  cagta[at]pm[dot]me
*/
const int analogInPin = A0;             
int data = 0;   
     
void setup() { 
  
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
  
}

void loop() {
  
  Serial.print("Sensor is working = " );                       
  Serial.println(data);   
  delay(750); 
                      
}

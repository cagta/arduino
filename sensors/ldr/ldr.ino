/**
 * This code includes usage of LDR on Arduino Uno.
 * Wiring diagram of LDR = http://communityofrobots.com/sites/default/files/images/u1/ldrarduino.jpg
 *
 * NOTE: Even if there is no connection between LDR and Arduino, you can see some results 
 * on serial monitor. You need to be sure of it's source. Don't forget to test LDR with some
 * light source.
 * 
 * @author Çağatay Tanyıldız
 * @email  cagataytanyildiz[at]protonmail[dot]com
*/
#define LDR_PIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("LDR test!");
}

void loop() {
  float light = analogRead(LDR_PIN);

  Serial.println("Sensor is working");
  Serial.println(light);
  delay(3000);
}



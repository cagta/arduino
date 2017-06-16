/**
 * This code includes usage of nRF24L01 on Arduino Uno.
 * Wiring diagram of nRF24L01 = http://starter-kit.nettigo.eu/wp-content/uploads/2014/12/nrf-ardino-en.png
 * Library source of nRF24L01 = https://tmrh20.github.io/RF24/
 * 
 * @author Çağatay Tanyıldız
 * @email  cagataytanyildiz[at]protonmail[dot]com
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/**
  CE (7) and CSN (8) pins
*/
RF24 radio(7, 8);

/**
  According to RF24 library document:
  
  Pipes 1-5 should share the first 32 bits. Only the least significant byte should be unique, e.g.
    openReadingPipe(1,0xF0F0F0F0AA);
    openReadingPipe(2,0xF0F0F0F066);
  Pipe 0 is also used by the writing pipe. So if you open pipe 0 for reading, 
  and then startListening(), it will overwrite the writing pipe.
  Ergo, do an openWritingPipe() again before write().  
*/
const byte address[][6] = {"BNode","1Node", "2Node", "3Node"};

void setup()
{
  Serial.begin(9600);
  
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(address[1]);
  radio.stopListening();
}

void loop()
{
  // Before writing to pipe we need to stop radio first.
  radio.stopListening();

  //Sending message to "2Node" address
  radio.openWritingPipe(address[2]);
  const char text[] = "Hello World 2";
  radio.write(&text, sizeof(text));
  
  delay(1000);

  //Sending message to "3Node" address
  radio.stopListening();
  radio.openWritingPipe(address[3]);
  const char text1[] = "Hello World 3";
  radio.write(&text1, sizeof(text1));
  
  delay(1000);

  //Sending message to "BNode" address
  radio.stopListening();
  radio.openWritingPipe(address[1]);
  const char text2[] = "Hello World B";
  radio.write(&text2, sizeof(text2));
  
  delay(1000);
}

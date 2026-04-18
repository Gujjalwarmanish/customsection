#include <Arduino.h>
#define BUFFER_SIZE 16
char index = 0;

char  buffer[BUFFER_SIZE]__attribute__((section(".buffer")));

volatile uint8_t head = 0;
volatile uint8_t tail = 0;

char data = 'm';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  
}

void loop() {
 if( Serial .available()){
  data = Serial.read(); 
  uint8_t next = (head + 1 ) % BUFFER_SIZE;
  if ( next != head ){
    buffer[head] = data;
    head = next;
  }
 }
 if(tail != head){
  data =buffer[tail];
  tail = (tail + 1) % BUFFER_SIZE;

 }
 Serial.println(data);
 for(int i = 0; i <= BUFFER_SIZE; i++){
  Serial.println(buffer[i]);
 }
 
 
 
  
 
}

// put function definitions here:
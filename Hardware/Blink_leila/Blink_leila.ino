/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
int led = 23;
int potar = A8;
int slide = A7;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(potar, INPUT);     
  pinMode(slide, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  int potarvalue=analogRead(potar);
  int slidervalue = analogRead(slide);
  int i=0;
  int j=0;
  i=map(potarvalue,0,1024,255,0);
  j=map(slidervalue,0,1024,255,0);
  analogWrite(led, i);
  delay(j);
  analogWrite(led, 0);
  delay(j);
  
//  int i = 0;
//  for(i=0;i<256;i++){
//    analogWrite(led, i);
//    delay(50);
//  }
//
//  for(i = 255;i>=0;i--){
//    analogWrite(led, i);
//    delay(50);
//  }
}

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
int led = 23;
//int potar = A5;
//int slide = A7;
int joyx = A5;
int joyy = A7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  //pinMode(potar, INPUT);     
  //pinMode(slide, INPUT);
  pinMode(joyx, INPUT);     
  pinMode(joyy, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int intensity_value = analogRead(joyx);
  int freq_value = analogRead(joyy);
  int i=0;
  int j=0;
  i = map(intensity_value,0,1024,255,0);
  j = map(freq_value,0,1024,255,0);
  analogWrite(led, i);
  delay(j);
  analogWrite(led, 0);
  delay(j);
  

// breathing LED  
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

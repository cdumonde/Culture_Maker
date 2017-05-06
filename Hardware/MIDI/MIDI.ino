/* comunication par protocol MIDI */
#include <Bounce.h>
#include <string.h>

// the MIDI continuous controller for each analog input
int ccSlider1=10;
int ccSlider2=11;
int ccJoystick1=12;
int ccJoystick2=13;
int ccIR=14;
int ccPotentiometre1=15;
int ccPotentiometre2=16;
int ccEncodeur1=17;
int ccEncodeur2=18;
int ccPotar=19;
//Notes for diffrent buttons
int noteButton1=60;
int noteButton2=63;

// id for the composents
#define ID_BUTTON1 0
#define ID_BUTTON2 1
#define ID_SLIDER1 2
#define ID_SLIDER2 3
#define ID_IR 4
#define ID_JOYSTICK 5
#define ID_POTENTIOMETRE1 6
#define ID_POTENTIOMETRE2 7
#define ID_POTAR 8
#define ID_ENCODEUR1 9
#define ID_ENCODEUR2 10

#define POTAR
// the MIDI channel number to send messages
const int channel = 1;
// the Teensy inputs pins
int inputs[12][2];
// the id for each composants
int identifiant[10];
int nbrModules = 10;

// create sensor variable
int joystick[2];
int Slider1,Slider2,IR,Potentiometre1,Potentiometre2,Encodeur1,Encodeur2,Potar,But1,But2;

// Create Bounce objects for each button.
Bounce button0 = Bounce(But1, 5);
Bounce button1 = Bounce(But2, 5); 


void setup() {
}

// store previously sent values, to detect changes
int previousSlider1 = -1;
int previousSlider2 = -1;
int previousJoystick[2] = {-1,-1};
int previousIR = -1;
int previousPotar = -1;
int previousPotentiometre1 = -1;
int previousPotentiometre2 = -1;
int previousEncodeur1 = -1;
int previousEncodeur2 = -1;


elapsedMillis msec = 0;

void loop() {
  // Configure each input with each composant
  for(int i=0; i < nbrModules ; i++){
    if(identifiant[i]== ID_BUTTON1)
      But1 = inputs[i][0];
    else if(identifiant[i]== ID_BUTTON2)
      But2 = inputs[i][0];
    else if (identifiant[i]== ID_SLIDER1)
      Slider1 = analogRead(inputs[i][0]) / 8;
    else if (identifiant[i]== ID_SLIDER2)
      Slider2 = analogRead(inputs[i][0]) / 8;
    else if (identifiant[i]== ID_IR)
      IR = analogRead(inputs[i][1]) / 8;
    else if (identifiant[i]== ID_JOYSTICK){
      joystick[0] = analogRead(inputs[i][0]) / 8;
      joystick[1] = analogRead(inputs[i][1]) / 8;
    }
    else if (identifiant[i]== ID_POTENTIOMETRE1)
      Potentiometre1 = analogRead(inputs[i][0]) / 8;
    else if (identifiant[i]== ID_POTENTIOMETRE2)
      Potentiometre2 = analogRead(inputs[i][0]) / 8;
    else if (identifiant[i]== ID_POTAR)
      Potar = analogRead(inputs[i][0]) / 8;
    else if (identifiant[i]== ID_ENCODEUR1)
      Encodeur1 = analogRead(inputs[i][0]) / 8;
    else if (identifiant[i]== ID_ENCODEUR2)
      Encodeur2 = analogRead(inputs[i][0]) / 8;      
}
  // Configure the pins for input mode with pullup resistors.
  pinMode(But1, INPUT_PULLUP);
  pinMode(But2, INPUT_PULLUP);
  // Update all the buttons.
  button0.update();
  button1.update();
  
  // Check each button for "falling" edge.
  if (button0.fallingEdge()) {
    usbMIDI.sendNoteOn(noteButton1, 127, channel);  
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(noteButton2, 127, channel);  
  }
  // Check each button for "rising" edge
  if (button0.risingEdge()) {
    usbMIDI.sendNoteOff(noteButton1, 0, channel);  
  }
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(noteButton2, 0, channel);  
  }

  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
  if (msec >= 20) {
    msec = 0;
    // only transmit MIDI messages if analog input changed
    if (Slider1 != previousSlider1) {
      usbMIDI.sendControlChange(ccSlider1, Slider1, channel);
      previousSlider1 = Slider1;
    }
    if (Slider2 != previousSlider2) {
      usbMIDI.sendControlChange(ccSlider2, Slider2, channel);
      previousSlider2 = Slider2;
    }
    if (IR != previousIR) {
      usbMIDI.sendControlChange(ccIR, IR, channel);
      previousIR = IR;
    }
    if (Potentiometre1 != previousPotentiometre1) {
      usbMIDI.sendControlChange(ccPotentiometre1, Potentiometre1, channel);
      previousPotentiometre1 = Potentiometre1;
    }
    if (Potentiometre2 != previousPotentiometre2) {
      usbMIDI.sendControlChange(ccPotentiometre2, Potentiometre2, channel);
      previousPotentiometre2 = Potentiometre2;
    }
    if (Encodeur1 != previousEncodeur1) {
      usbMIDI.sendControlChange(ccEncodeur1, Encodeur1, channel);
      previousEncodeur1 = Encodeur1;
    }
    if (Encodeur2 != previousEncodeur2) {
      usbMIDI.sendControlChange(ccEncodeur2, Encodeur2, channel);
      previousEncodeur2 = Encodeur2;
    }
    if (Potar != previousPotar) {
      usbMIDI.sendControlChange(ccPotar, Potar, channel);
      previousPotar = Potar;
    }
    if (joystick[0] != previousJoystick[0]) {
      usbMIDI.sendControlChange(ccJoystick1, joystick[0], channel);
      previousJoystick[0] =  joystick[0];
    }
    if (joystick[1] != previousJoystick[1]) {
      usbMIDI.sendControlChange(ccJoystick2, joystick[1], channel);
      previousJoystick[1]=  joystick[1];
    }
  }
  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}


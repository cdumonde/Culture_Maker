#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <vector>

enum FONCTION_TYPE
{
    SHORTCUT,
    CUSTOM,//TODO
    MIDI
};
enum ADVANCED_FUNCTION //TODO
{
    ECHO,
    TREEBLE,
    BASS,
    GAIN
};
enum MESSAGE_TYPE 
{
    // Channel messages
    NOTE_OFF        = 0x80,
    NOTE_ON         = 0x90,
    POLYTOUCH       = 0xA0,
    CONTROL_CHANGE  = 0xB0,
    PROGRAM_CHANGE  = 0xC0,
    AFTERTOUCH      = 0xD0,
    PITCHWHEEL      = 0xE0,
    // System common messages
    SYSEX           = 0xF0,
    QUARTER_FRAME   = 0xF1,
    SONG_POS        = 0xF2,
    SONG_SELECT     = 0xF3,
    TUNE_REQUEST    = 0xF6,
    // System real time messages
    CLOCK           = 0xF8,
    START           = 0xFA,
    CONTINUE        = 0xFB,
    STOP            = 0xFC,
    ACTIVE_SENSING  = 0xFE,
    RESET           = 0xFF
};
enum CONTROLLER_TYPE
{
	// Type de module
	BUTTON,
    JOYSTICK,
	SLIDER,
	PIEZO,
	POTENTIOMETER,
	IR_SENSOR,
	ENCODER,
	UNKNOWN
};
enum NOTE
{
    C = 0,
    C2 = 1,
    D = 2,
    D2 = 3,
    E = 4,
    F = 5,
    F2 = 6,
    G = 7,
    G2 = 8,
    A = 9,
    A2 = 10,
    B = 11
};


/*std::vector<std::string> controller_type_map = { "Button",
                                                 "Slider",
                                                 "Piezo",
                                                 "Potentiometer",
                                                 "Infrared Sensor",
                                                 "Encoder", 
                                                 "Unknown"};*/

#endif //TYPES_H
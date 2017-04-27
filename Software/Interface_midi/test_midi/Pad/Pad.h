#ifndef PAD_H
#define PAD_H

#include <vector>

#include "RtMidi.h"
#include "Controller.h"
#include "Types.h"

class Pad {

public:
    Pad(int height = 1, int width = 1);
    bool set_function(FONCTION_TYPE funct);
	bool set_function(FONCTION_TYPE funct, std::string shortcut);
    bool set_function(FONCTION_TYPE funct, NOTE note, char hauteur);
    bool set_function(FONCTION_TYPE funct, ADVANCED_FUNCTION f);
private:
    RtMidiIn message_in;
    RtMidiOut message_out;
    std::vector<Controller> control;
    int height, width;
};

#endif //PAD_H
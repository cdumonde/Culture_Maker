#ifndef PAD_H
#define PAD_H

#include "RtMidi.h"
#include "Control.h"

enum TYPE 
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

class Pad {

public:

private:
    RtMidi
};

#endif //PAD_H
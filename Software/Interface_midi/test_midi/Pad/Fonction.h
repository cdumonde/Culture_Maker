#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "Types.h"

class Fonction
{
public:
    Fonction(FONCTION_TYPE funct = MIDI);
    ~Fonction();

    bool set_function(FONCTION_TYPE funct, short shorcut);
    bool set_function(FONCTION_TYPE funct, NOTE note, char hauteur);
    bool set_function(FONCTION_TYPE funct, ADVANCED_FUNCTION f);
    char exec_funct(bool b);

private:
    short m_shortcut;
    char m_hauteur;
    NOTE m_note;
    ADVANCED_FUNCTION m_f;
    FONCTION_TYPE m_funct;

    XKeyEvent createKeyEvent(Display *display, Window &win, Window &winRoot, bool press, int keycode, int modifiers);
};


#endif //FONCTION_H
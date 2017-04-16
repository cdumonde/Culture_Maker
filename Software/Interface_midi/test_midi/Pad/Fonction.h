#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
#include <string>
#include "Types.h"
#ifdef __linux__
#include <X11/keysym.h>
//Lib bug
extern "C" {
#include <xdo.h>
}
#endif

enum BUTTON_STATUS
{
    DOWN,
    UP
};

class Fonction
{
public:
    Fonction(FONCTION_TYPE funct = MIDI);
    ~Fonction();

    bool set_function(FONCTION_TYPE funct, std::string shorcut);
    bool set_function(FONCTION_TYPE funct, NOTE note, char hauteur);
    bool set_function(FONCTION_TYPE funct, ADVANCED_FUNCTION f);
    char exec_funct();

private:
    std::string m_shortcut;
    char m_hauteur;
    NOTE m_note;
    ADVANCED_FUNCTION m_f;
    FONCTION_TYPE m_funct;
};


#endif //FONCTION_H
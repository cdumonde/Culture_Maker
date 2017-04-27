/* This file is part of the Culture_Maker project,
*  It defines the behavior of the midi controller function.
*  Copyright (C) 2017 by Cedric Dumondelle
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.

*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Fonction.h"
#include "Types.h"

Fonction::Fonction(FONCTION_TYPE funct)
{
    m_funct = funct;
}
Fonction::~Fonction()
{

}
bool Fonction::set_function(FONCTION_TYPE funct)//DEFAULT
{
    m_funct = funct;
    return true;
}
bool Fonction::set_function(FONCTION_TYPE funct, std::string shortcut)//SHORTCUT
{
    m_funct = funct;
    if(m_funct == SHORTCUT)
    {
        m_shortcut = shortcut;
        return true;
    }
    return false;
}
bool Fonction::set_function(FONCTION_TYPE funct, NOTE note, char hauteur)//MIDI
{
    m_funct = funct;
    if(m_funct == MIDI && hauteur >= 0 && hauteur <= 10)
    {
        m_note = note;
        m_hauteur = hauteur;
        return true;
    }
    return false;

}
bool Fonction::set_function(FONCTION_TYPE funct, ADVANCED_FUNCTION f)//CUSTOM
{
    m_funct = funct;
    if(m_funct == CUSTOM)
    {
        m_f = f;
        return true;
    }
    return false;
}
char Fonction::exec_funct()
{
    #ifdef __linux__
    xdo_t *window = xdo_new(NULL);
    #elif _WIN32
    //TODO
    #endif
    switch (m_funct)
    {
        case MIDI:
            return 12*m_hauteur + (char)m_note;
        break;
        case SHORTCUT:
            #ifdef __linux__
            xdo_send_keysequence_window(window, CURRENTWINDOW, m_shortcut.c_str(), 0);
            #elif _WIN32

            #endif         
        break;
        default:
        //TODO
        break;
    }
    return 0;
}
FONCTION_TYPE Fonction::get_function()
{
    return m_funct;
}

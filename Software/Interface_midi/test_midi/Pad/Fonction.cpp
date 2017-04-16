#include "Fonction.h"
#include "Types.h"

Fonction::Fonction(FONCTION_TYPE funct)
{
    m_funct = funct;
}
Fonction::~Fonction()
{

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
    std::vector<std::string> cmd;
    size_t pos = 0, pos_1 = 0;
    while(pos != m_shortcut.npos)
    {
        pos = m_shortcut.find("+", pos_1);
        cmd.push_back(m_shortcut.substr(pos_1, pos));
        if(pos != m_shortcut.npos)
        {
            pos_1 = pos +1;
        }
    }
    std::cout << "SIZE : " << cmd.size() << std::endl;
    #ifdef __linux__
    xdo_t *window = xdo_new(NULL);
    #elif _WIN32

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

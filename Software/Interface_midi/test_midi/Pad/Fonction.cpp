#include "Fonction.h"
#include "Types.h"

Fonction::Fonction(FONCTION_TYPE funct)
{
    m_funct = funct;
}
Fonction::~Fonction()
{

}
bool Fonction::set_function(FONCTION_TYPE funct, short shortcut)//SHORTCUT
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
char Fonction::exec_funct(bool b)
{
    Display *display;
    Window winRoot;
    Window winFocus;
    int revert;
    XKeyEvent event;
    switch (m_funct)
    {
        case MIDI:
            return 12*m_hauteur + (char)m_note;
        break;
        case SHORTCUT:
            display = XOpenDisplay(0);
            if(display == NULL)
                return -1;
            winRoot = XDefaultRootWindow(display);
            XGetInputFocus(display, &winFocus, &revert);
            event = createKeyEvent(display, winFocus, winRoot, b, m_shortcut, 0);
            XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
            XCloseDisplay(display);
        break;
        default:
        //TODO
        break;
    }
    return 0;
}
XKeyEvent Fonction::createKeyEvent(Display *display, Window &win, Window &winRoot, bool press, int keycode, int modifiers)
{
    XKeyEvent event;

    event.display     = display;
    event.window      = win;
    event.root        = winRoot;
    event.subwindow   = None;
    event.time        = CurrentTime;
    event.x           = 1;
    event.y           = 1;
    event.x_root      = 1;
    event.y_root      = 1;
    event.same_screen = True;
    event.keycode     = XKeysymToKeycode(display, keycode);
    event.state       = modifiers;

    if(press)
        event.type = KeyPress;
    else
        event.type = KeyRelease;

    return event;
}

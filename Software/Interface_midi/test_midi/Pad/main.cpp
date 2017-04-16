#include "Fonction.h"
#include "iostream"
#include <unistd.h>

using namespace std;

int main()
{
    Fonction funct(SHORTCUT);
    
    funct.set_function(SHORTCUT, "Ctrl+Alt+Delete");

    sleep(5);
    cout << XKeysymToString(XK_Delete) << endl;
    funct.exec_funct();
    return 1;
}
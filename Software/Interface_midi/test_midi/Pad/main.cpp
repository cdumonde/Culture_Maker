#include "Fonction.h"
#include "iostream"
#include <unistd.h>

using namespace std;

int main()
{
    string caractere;
    setlocale(LC_ALL, "fr-FR. UTF-8");
    Fonction funct(SHORTCUT);
    while(1)
    {
        cin >> caractere;
        cout << (int)caractere[0] << endl;
    }
}
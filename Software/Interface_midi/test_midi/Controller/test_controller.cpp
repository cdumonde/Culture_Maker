// Clovis Durand

#include "Controller.h"
using namespace std;

int main()
{
	Controller c1(0xF0, 0x0F, PIEZO);
	cout << "CREATED c1 : 0xF0, 0x0F, PIEZO" << endl;
	cout << c1.infosController() << endl;

	/*unsigned char bite = 0xFF; // LOLMDR
	cout << "test uChar_to_hex avec 0xFF : " << uChar_to_hex(bite) << endl;
	cout << "bite = 0x" << hex << uppercase << (int)bite << nouppercase << endl;*/

	c1.saveController();

}

// Notes : 
	//error: invalid conversion from 'int' to 'CONTROLLER_TYPE' [-fpermissive] Controller c1(0xF0, 0x0F, 3);
		// On peux donc pas utiliser de int pour designer un type
	// Il faut caster les uChar en int pour pouvoir les print correctement
		// Pourquoi ?


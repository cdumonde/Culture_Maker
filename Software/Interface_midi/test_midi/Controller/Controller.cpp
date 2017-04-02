// Clovis Durand

#include "Controller.h"
using namespace std;

// Con/Destructeurs -------------------------------------------------
Controller::Controller(unsigned char id_physical, 
				 unsigned char id_function, 
				 CONTROLLER_TYPE type): m_id_phys(id_physical), m_id_funct(id_function), m_type(type)
{
	// Contructeur par defaut
}

Controller::Controller(unsigned char const id)
{
	loadController(id);
}

Controller::~Controller()
{
	// Destructeur
}

// Afficheurs -------------------------------------------------------
string Controller::infosController(void) const
{
	return uChar_to_hex(get_id_phys()) + "/" + uChar_to_hex(get_id_funct()) + "/" + type_to_string();
}
//void print_Controller(void) const;

// Accesseurs -------------------------------------------------------
unsigned char Controller::get_id_phys(void) const
{
	return m_id_phys;
}

unsigned char Controller::get_id_funct(void) const
{
	return m_id_funct;
}

CONTROLLER_TYPE Controller::get_type(void) const
{
	return m_type;
}

/*unsigned int Controller::get_type_uInt(void) const
{
	return m_type;
}*/

unsigned char Controller::get_velocity(void) const
{
	return m_velocity;
}

unsigned char Controller::get_value(void) const
{
	return m_value;
}

// Mutateurs ---------------------------------------------------------
void Controller::set_id_phys(unsigned char const &id)
{
	m_id_phys = id;
}
void Controller::set_id_funct(unsigned char const &id)
{
	m_id_funct = id;
}

void Controller::set_type(CONTROLLER_TYPE const &type)
{
	m_type = type;
}

void Controller::set_velocity(unsigned char const &velocity)
{
	m_velocity = velocity;
}

void Controller::set_value(unsigned char const &value)
{
	m_value = value;
}

// File Management --------------------------------------------------
bool Controller::loadController(unsigned char const &id)
{
	string filename = uChar_to_hex(id) + ".mod";
	return loadController(filename);
}

bool Controller::loadController(string const filename)
{
	ifstream flux(filename);

	if(flux)
	{
		string ligne;
		getline(flux, ligne);
		flux.close();

		string infos[3];
		unsigned int pos, taille;

		for (int i = 0; i < 3; i++)
		{
			taille = ligne.size();
			if (taille != 0)
			{
				pos  = ligne.find("/");
				infos[i] = ligne.substr(0, pos);
				ligne    = ligne.substr(pos + 1, taille - 1);
			}
		}

		m_id_phys  = stoi(infos[0]);
		m_id_funct = stoi(infos[1]);
		m_type	   = string_to_type(infos[2]);

		cout << "LOADED : " << *this << " from " << filename << endl;
	}
	else
	{
		cerr << "ERROR  : Cannot open file [" << filename << "] (read mode)." << endl;
		return 1;
	}
	return 0;
}

bool Controller::saveController(void) const
{
	string filename = uChar_to_hex(m_id_phys) + ".mod";
	ofstream flux(filename.c_str(), ios::trunc); // ofstream o comme output
	//Déclaration d'un flux permettant d'écrire dans un fichier.
	//ios::app = seek the end of file before you write
	//ios::trunc = discard the contents of the stream when opening

	string infos = infosController();

	if(flux)
	{
		flux << infos;
		flux.close();
		cout << "WROTE  : " << infos << " in " << filename << endl;

		return 0;
	}
	else
	{
		cerr << "ERROR  : Cannot open file [" << filename << "] (write mode)." << endl;
		return 1;
	}
}

// Méthodes privées diverses ----------------------------------------
string Controller::type_to_string(void) const
// Renvoie un string decrivant le type de controlleur
{
	if (m_type == 0)
		return "BUTTON";
	else if (m_type == 1)
		return "SLIDER";
	else if (m_type == 2)
		return "PIEZO";
	else if (m_type == 3)
		return "POTENTIOMETER";
	else if (m_type == 4)
		return "IR_SENSOR";
	else if (m_type == 5)
		return "ENCODER";
	else
		return "UNKNOWN";
}

CONTROLLER_TYPE Controller::string_to_type(string strtype) const
// Renvoie le bon type en fonction d'un string correspondant
{
	if (strtype == "BUTTON")
		return BUTTON;
	else if (strtype == "SLIDER")
		return SLIDER;
	else if (strtype == "PIEZO")
		return PIEZO;
	else if (strtype == "POTENTIOMETER")
		return POTENTIOMETER;
	else if (strtype == "IR_SENSOR")
		return IR_SENSOR;
	else if (strtype == "ENCODER")
		return ENCODER;
	else // strtype non correcpondant ou strtype == "UNKNOWN"
		return UNKNOWN;
}



// Operateurs -------------------------------------------------------
ostream &operator<<(ostream &flux, Controller const &c)
{
	flux << c.infosController();
	return flux;
}

string uChar_to_hex(unsigned char i)
{
	stringstream stream;
	stream << "0x";
	if (i < 16)
		stream << "0" << hex << uppercase << (int)i << nouppercase;
	else
		stream << hex << uppercase << (int)i << nouppercase;
	return stream.str();
}
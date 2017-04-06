// Clovis Durand

#include "Controller.h"
using namespace std;

// Con/Destructors -------------------------------------------------
Controller::Controller(unsigned char id_physical, 
				       unsigned char id_function, 
				       CONTROLLER_TYPE type): m_id_phys(id_physical), m_id_funct(id_function), m_type(type)
{
	// Dafault Controller
}

Controller::Controller(string const filename)
{
	loadController(filename);
}

Controller::~Controller()
{
	// Default Destructor
}

// Printers ---------------------------------------------------------
string Controller::infosController(void) const
{
	return uChar_to_hex(get_id_phys()) + "/" + uChar_to_hex(get_id_funct()) + "/" + type_to_string();
}

// Getters ----------------------------------------------------------
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

unsigned char Controller::get_velocity(void) const
{
	return m_velocity;
}

unsigned char Controller::get_value(void) const
{
	return m_value;
}

// Setters ----------------------------------------------------------
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

	#ifdef DEBUG
		cout << "Attempt to load from [" << filename << "]" << endl;
	#endif // DEBUG

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
				#ifdef DEBUG
					cout << "ligne = " << ligne << endl;
					cout << "infos[i] = " << infos[i] << endl;
				#endif // DEBUG
				ligne    = ligne.substr(pos + 1, taille - 1);
			}
		}

		// stoul to convert to an unsigned long, and then cast to unsigned char
		// because uChar takes the associated caracter, not the exact value
		m_id_phys  = (unsigned char)stoul(infos[0], 0, 16);
		m_id_funct = (unsigned char)stoul(infos[1], 0, 16);
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
	ofstream flux(filename.c_str(), ios::trunc);
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

// Misc. private methods --------------------------------------------
string Controller::type_to_string(void) const
// Returns a string corresponding to the m_type of the controller
{
	switch (m_type)
	{
		case BUTTON:
			return "BUTTON";
		case SLIDER:
			return "SLIDER";
		case PIEZO:
			return "PIEZO";
		case POTENTIOMETER:
			return "POTENTIOMETER";
		case IR_SENSOR:
			return "IR_SENSOR";
		case ENCODER:
			return "ENCODER";
		case default:
			return "UNKNOWN";
	}
}

CONTROLLER_TYPE Controller::string_to_type(string strtype) const
// Returns the correct type corresponding with the input string type. 
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
	else // non corresponding strtypr or strtype == "UNKNOWN"
		return UNKNOWN;
}



// Operators -------------------------------------------------------
ostream &operator<<(ostream &flux, Controller const &c)
{
	flux << c.infosController();
	return flux;
}

// Misc. functions --------------------------------------------------

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


// Clovis Durand

#include "Controller.h"
using namespace std;

// Con/Destructeurs -------------------------------------------------
Controller::Controller(unsigned char id_physical, 
				 unsigned char id_function, 
				 CONTROLLER_TYPE type)
{
	// Contructeur
	m_id_phys(id_physical);
	m_id_funct(id_function);
	m_type(type);
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
string infosController(void) const
{
	return to_string(get_id_phys()) + "/" + to_string(get_id_funct()) + "/" + type_to_string(get_type());
}
void print_Controller(void) const

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
	string filename = to_string(id) + ".mod"
	return loadController(filename);
}

bool Controller::loadController(string const filename)
{
	ifstream flux(filename)

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

		m_id_phys  = infos[0];
		m_id_funct = infos[1];
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
	string filename = to_string(id) + ".mod";
	ofstream flux(filename.c_str(), ios::app); // ofstream o comme output
	//Déclaration d'un flux permettant d'écrire dans un fichier.
	//ios::app = seek the end of file before you write

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

// Operateurs -------------------------------------------------------
ostream &operator<<(ostream &flux, Controller const &c)
{
	flux << c.infosController();
	return flux;
}
/* This file is part of the Culture_Maker project,
*  It defines the behavior or an abstract midi controller.
*  Copyright (C) 2017 by Clovis Durand
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

#include "Controller.h"

using namespace std;

// Default constructor
Controller::Controller(unsigned char id_physical, unsigned char id_function, CONTROLLER_TYPE type)
{
    set_id_phys(id_physical);
    set_id_funct(id_function);
    set_type(type);
}

// Contructor allowing to load values from a file
Controller::Controller(string const filename)
{
	loadController(filename);
}

// Destructor
Controller::~Controller()
{

}

// Accessors
unsigned char Controller::get_id_phys(void) const
{
	return m_id_phys;
}

unsigned char Controller::get_id_funct(void) const
{
	return m_id_funct;
}

unsigned char Controller::get_velocity(void) const
{
	return m_velocity;
}

unsigned char Controller::get_value(void) const
{
	return m_value;
}

CONTROLLER_TYPE Controller::get_type(void) const
{
	return m_type;
}

// Mutators
void Controller::set_id_phys(unsigned char const &id)
{
	m_id_phys = id;
}
void Controller::set_id_funct(unsigned char const &id)
{
	m_id_funct = id;
}

void Controller::set_velocity(unsigned char const &velocity)
{
	m_velocity = velocity;
}

void Controller::set_value(unsigned char const &value)
{
	m_value = value;
}

void Controller::set_type(CONTROLLER_TYPE const &type)
{
	m_type = type;
}

// Loads the controller settings from a file.
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

		// stoul pour convertir en unsigned long, puis cast en (unsigned char)
		// l'utilisation de uChar directement prends le caractère associé, 
		// pas la valeur de l'octet
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

// Loads the controller settings from a file directly by its id.
bool Controller::loadController(unsigned char const &id)
{
	string filename = id + ".mod";
	return loadController(filename);
}

// Save controller settings
bool Controller::saveController(void) const
{
	string filename = m_id_phys + ".mod";
    
    // Opening file in truncate mode
	ofstream flux(filename.c_str(), ios::trunc);

    // Reading controller settings
	string infos = infosController();

    // Writing output
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

// Provides human-readable strings for the CONTROLLER_TYPE type
string Controller::type_to_string(void) const
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

// Overloaded << operator for data output
ostream &operator<<(ostream &flux, Controller const &c)
{
	flux << c.infosController();
	return flux;
}



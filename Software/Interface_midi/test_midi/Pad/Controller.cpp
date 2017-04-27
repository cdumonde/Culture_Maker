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
Controller::Controller(unsigned char id_physical, FONCTION_TYPE function, CONTROLLER_TYPE type)
{
	m_funct = new Fonction(function);
    set_id_phys(id_physical);
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
	delete m_funct;
}

// Getters
unsigned char Controller::get_id_phys(void) const
{
	return m_id_phys;
}

FONCTION_TYPE Controller::get_id_funct(void) const
{
	return m_funct->get_function();
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

// Setters
void Controller::set_id_phys(unsigned char const id)
{
	m_id_phys = id;
}
bool Controller::set_function(FONCTION_TYPE funct, std::string shortcut)
{
	return m_funct->set_function(funct, shortcut);
}
bool Controller::set_function(FONCTION_TYPE funct, NOTE note, char hauteur)
{
	return m_funct->set_function(funct, note, hauteur);
}
bool Controller::set_function(FONCTION_TYPE funct, ADVANCED_FUNCTION f)
{
	return m_funct->set_function(funct, f);
}
void Controller::set_velocity(unsigned char const velocity)
{
	m_velocity = velocity;
}
void Controller::set_value(unsigned char const value)
{
	m_value = value;
}
void Controller::set_type(CONTROLLER_TYPE const type)
{
	m_type = type;
}
// Loads the controller settings from a file.
bool Controller::loadController(const string filename)
{
	ifstream flux(filename.c_str());

	#ifdef DEBUG
		cout << "Attempt to load from [" << filename << "]" << endl;
	#endif // DEBUG

	if(flux.is_open())
	{
		char c;
		for (int i = 0; i < 3; i++)
		{
			c = flux.get();
			switch(i)
			{
				case 0:
				m_funct->set_function((FONCTION_TYPE)c);
				break;
				case 1:
				m_id_phys = (unsigned char)c;
				break;
				default:
				m_type = (CONTROLLER_TYPE)c;
				break;
			}	
		}
		cout << "LOADED : " << *this << " from " << filename << endl;
	}
	else
	{
		cerr << "ERROR  : Cannot open file [" << filename << "] (read mode)." << endl;
		return false;
	}
	return true;
}
// Loads the controller settings from a file directly by its id.
bool Controller::loadController(unsigned char const id)
{
	stringstream filename;
	filename << m_id_phys << ".mod";
	return loadController(filename.str());
}
// Save controller settings
bool Controller::saveController(void) const
{
	stringstream filename;
	filename << m_id_phys << ".mod";
    
    // Opening file in truncate mode
	ofstream flux(filename.c_str());
	
    // Writing output
	if(flux.is_open())
	{
		char funct = (char)m_funct->get_function();
		char type = (char)m_type;
		flux.write(&funct, 1);
		flux.write(&m_id_phys, 1);
		flux.write(&type, 1);
		flux.close();
		return 0;
	}
	else
	{
		cerr << "ERROR  : Cannot open file [" << filename << "] (write mode)." << endl;
		return 1;
	}
}
// Overloaded << operator for data output
ostream &operator<<(ostream &flux, const Controller &c)
{
	flux << c.infosController();
	return flux;
}
string Controller::infosController() const
{
	stringstream ss;
	ss << "ID : " << (int)m_id_phys << endl;
	switch(m_type)
	{
		case BUTTON:
		ss << "Type : Button" << endl;
		break;
		case JOYSTICK:
		ss << "Type : Joystick" << endl;
		break;
		case SLIDER:
		ss << "Type : Slider" << endl;
		break;
		case PIEZO:
		ss << "Type : Piezo" << endl;
		break;
		case POTENTIOMETER:
		ss << "Type : Potentiometer" << endl;
		break;
		case IR_SENSOR:
		ss << "Type : Infrared sensor" << endl;
		break;
		case ENCODER:
		ss << "Type : Encoder" << endl;
		break;
		default:
		ss << "Type : Unknown" << endl;
		break;
	}
	switch(m_funct->get_function())
	{
		case MIDI:
		ss << "Function : Midi" << endl;
		break;
		case SHORTCUT:
		ss << "Function : Shortcut" << endl;
		break;
		default:
		ss << "Function : Custom" << endl;
		break;
	}
	return ss.str();
}

char Controller::exec_funct()
{
	return m_funct->exec_funct();
}


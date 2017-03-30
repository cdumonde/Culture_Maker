#include "Controller.h"
using namespace std;

// Con/Destructeurs
Controller::Controller(unsigned char id_physical, 
				 unsigned char id_function, 
				 ControllerER_TYPE type)
{
	// Contructeur
	m_id_phys(id_physical);
	m_id_funct(id_function);
	m_type(type);
}

Controller::Controller(string const filename)
{
	loadController(filename);
}

Controller::~Controller()
{
	// Destructeur
}

// Accesseurs
unsigned char Controller::get_id_phys(void) const
{
	return m_id_phys;
}

unsigned char Controller::get_id_funct(void) const
{
	return m_id_funct;
}

ControllerER_TYPE Controller::get_type(void) const
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

// Mutateurs
void Controller::set_id_phys(unsigned char const &id)
{
	m_id_phys = id;
}
void Controller::set_id_funct(unsigned char const &id)
{
	m_id_funct = id;
}

void Controller::set_type(ControllerER_TYPE const &type)
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
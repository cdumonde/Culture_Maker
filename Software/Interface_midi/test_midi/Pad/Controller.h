#ifndef Controller_H
#define Controller_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Types.h"
#include "Fonction.h"

class Controller
{
public:
	// Constructor
	Controller(unsigned char const id_physical = 0,	FONCTION_TYPE function = MIDI, CONTROLLER_TYPE type = UNKNOWN);
	Controller(std::string const filename);
	~Controller();

	// Printer
	void print_Controller(void) const;

	// Getters
	unsigned char get_id_phys(void) const;
	FONCTION_TYPE get_id_funct(void) const;
	unsigned char get_velocity(void) const;
	unsigned char get_value(void) const;
    CONTROLLER_TYPE get_type(void) const;
	char exec_funct();

	// Setters
	void set_id_phys(unsigned char const id);
	bool set_function(FONCTION_TYPE funct);
	bool set_function(FONCTION_TYPE funct, std::string shortcut);
    bool set_function(FONCTION_TYPE funct, NOTE note, char hauteur);
    bool set_function(FONCTION_TYPE funct, ADVANCED_FUNCTION f);
	void set_velocity(unsigned char const velocity);
	void set_value(unsigned char const value);
    void set_type(CONTROLLER_TYPE const type);

	// File management
	bool loadController(unsigned char const id);
	bool loadController(std::string const filename);
	bool saveController(void) const;
	std::string infosController(void) const;

private:
	Fonction *m_funct;						// Function
	char m_id_phys;			 				// Controller ID
	char m_velocity, m_value;				// Controller values
    CONTROLLER_TYPE m_type; 				// Controller type


};

// Operators
std::ostream &operator<<(std::ostream &flux, Controller const &c);

#endif // Controller_H
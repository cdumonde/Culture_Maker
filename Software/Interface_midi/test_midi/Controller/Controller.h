// Clovis Durand

#ifndef Controller_H
#define Controller_H

#include <fstream> // File manipulation
#include <iostream>// cout, cin, cerr
#include <string>  // string declaration & manipulation
#include <cstdlib>
#include <sstream> // stringstream

//#define DEBUG

enum CONTROLLER_TYPE
{
	// Type de module
	BUTTON,
	SLIDER,
	PIEZO,			// Piezoelectric button
	POTENTIOMETER,
	IR_SENSOR,
	ENCODER, 		
	UNKNOWN 		// Default type
};

class Controller
{
public:
	// Con/Destructors
	Controller(unsigned char const id_physical = 0, 
			unsigned char const id_function    = 0, 
			CONTROLLER_TYPE type               = UNKNOWN);
	Controller(std::string const filename);
	~Controller();

	// Printers
	std::string infosController(void) const; 
	void print_Controller(void) const;

	// Getters
	unsigned char get_id_phys(void) const;
	unsigned char get_id_funct(void) const;
	CONTROLLER_TYPE get_type(void) const;
	unsigned char get_velocity(void) const;
	unsigned char get_value(void) const;

	// Setters
	void set_id_phys(unsigned char const &id);
	void set_id_funct(unsigned char const &id);
	void set_type(CONTROLLER_TYPE const &type);
	void set_velocity(unsigned char const &velocity);
	void set_value(unsigned char const &value);

	// Pre-Operators

	// Misc. Public Methods

	// File management
	bool loadController(unsigned char const &id);
	bool loadController(std::string const filename);
	bool saveController(void) const;

private:
	// Member variables
	unsigned char m_id_phys, m_id_funct; 	// IDs of module
	CONTROLLER_TYPE m_type; 				// Type of module
	unsigned char m_velocity, m_value;		// Values of the module

	// Misc. private methods
	std::string type_to_string(void) const;
	CONTROLLER_TYPE string_to_type(std::string strtype) const;
};

// Operators
std::ostream &operator<<(std::ostream &flux, Controller const &c);

// Misc. functions
std::string uChar_to_hex(unsigned char i);

#endif // Controller_H
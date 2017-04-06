// Clovis Durand

#ifndef Controller_H
#define Controller_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class Controller
{
public:
	// Con/Destructeurs
	Controller(unsigned char const id_physical = 0, unsigned char const id_function = 0, CONTROLLER_TYPE type = UNKNOWN);
	Controller(std::string const filename);
	~Controller();

	// Afficheurs
	std::string infosController(void) const; 
	void print_Controller(void) const;

	// Accesseurs
	unsigned char get_id_phys(void) const;
	unsigned char get_id_funct(void) const;
	unsigned char get_velocity(void) const;
	unsigned char get_value(void) const;
    CONTROLLER_TYPE get_type(void) const;


	// Mutateurs
	void set_id_phys(unsigned char const &id);
	void set_id_funct(unsigned char const &id);
	void set_velocity(unsigned char const &velocity);
	void set_value(unsigned char const &value);
    void set_type(CONTROLLER_TYPE const &type);

	// Pré-Operateurs

	// Méthodes publiques diverses

	// File management
	bool loadController(unsigned char const &id);
	bool loadController(std::string const filename);
	bool saveController(void) const;

private:
	// Attributs
	unsigned char m_id_phys, m_id_funct; 	// IDs du module concerné
	unsigned char m_velocity, m_value;		// Action sur le module concerné
    CONTROLLER_TYPE m_type; 				// Type de module concerné

};

// Operateurs
std::ostream &operator<<(std::ostream &flux, Controller const &c);

#endif // Controller_H
#ifndef Controller_H
#define Controller_H

enum ControllerER_TYPE
{
	// Type de module
	BUTTON,
	SLIDER,
	PIEZO,
	POTARD,
	CAPT_IR,
	ENCODER, 
	UNKNOWN
};

class Controller
{
public:
	// Con/Destructeurs
	Controller(unsigned char const id_physical, 
			unsigned char const id_function, 
			ControllerER_TYPE type = UNKNOWN);
	Controller(std::string const filename);
	~Controller();

	// Afficheurs
	void print_Controller(void) const;

	// Accesseurs
	unsigned char get_id_phys(void) const;
	unsigned char get_id_funct(void) const;
	ControllerER_TYPE get_type(void) const;
	unsigned char Controller::get_velocity(void) const;
	unsigned char Controller::get_value(void) const;

	// Mutateurs
	void set_id_phys(unsigned char const &id);
	void set_id_funct(unsigned char const &id);
	void set_type(ControllerER_TYPE const &type);
	void set_velocity(unsigned char const &velocity);
	void set_value(unsigned char const &value);

	// Pré-Operateurs

	// Méthodes publiques diverses

	// File management
	void loadController(std::string const filename);
	void saveController(std::string const filename);

private:
	// Attributs
	unsigned char m_id_phys, m_id_funct; 	// IDs du module concerné
	ControllerER_TYPE m_type; 					// Type de module concerné
	unsigned char m_velocity, m_value;		// Action sur le module concerné

	// Méthodes privées diverses
};

// Operateurs
std::ostream &operator<<(std::ostream &flux, Controller const &c);

#endif // Controller_H
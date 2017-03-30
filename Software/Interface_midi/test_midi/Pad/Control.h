#ifndef CONTROL_H
#define CONTROL_H

enum CONTROLER_TYPE
{
	// Type de module
	BUTTON,
	SLIDER,
	PIEZO,
	POTARD,
	CAPT_IR,
	ENCODER
};

class Control
{
public:
	// Con/Destructeurs
	Control();
	~Control();

	// Afficheurs
	void print_Control(void) const;

	// Accesseurs
	unsigned char get_id_phys(void) const;
	unsigned char get_id_funct(void) const;
	CONTROLER_TYPE get_type(void) const;

	// Mutateurs
	void set_id_phys(unsigned char id);
	void set_id_funct(unsigned char id);

	// Pré-Operateurs

	// Méthodes publiques diverses

private:
	// Attributs
	unsigned char id_phys, id_funct; 	// IDs du module concerné
	CONTROLER_TYPE type; 				// Type de module concerné
	unsigned char velocity, value;		// Action sur le module concerné

	// Méthodes privées diverses
};

// Operateurs
ostream &operator<<(ostream &flux, Control const &c);

#endif // CONTROL_H
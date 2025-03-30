#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include<iostream>
#include<string>

class ClapTrap
{
private:
	int			_fixedValue;
	std::string _Name; //Name, which is passed as a parameter to the constructor
	int			_Hit; //Hit points (10), representing the health of the ClapTrap
	int			_Life;	// Energy points (10)
	int			_Damage;// Attack damage (0)

public:
	ClapTrap(); // Constructeur par défaut.
	ClapTrap(std::string name);// Constructeur

	// ClapTrap(const ClapTrap& copy);    // Constructeur de copie
	// ClapTrap& operator=(const ClapTrap& other);// A copy assignment operator overload.
	~ClapTrap(void);

	std::string getName() const;
	// ClapTrap getHit() const;
	// ClapTrap getLife() const;
	// ClapTrap getDamage() const;

	void setName(std::string name) ;
	// ClapTrap setHit() const;
	// ClapTrap setLife() const;
	// ClapTrap setDamage() const;
	//.......
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap operator++(int);
	ClapTrap operator--(int);
};

#endif

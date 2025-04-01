#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include<iostream>
#include<string>

class ClapTrap
{
private:
	std::string _Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;

public:
	ClapTrap(); // Constructeur par défaut.
	ClapTrap(std::string name);// Constructeur
	ClapTrap(const ClapTrap& copy);    // Constructeur de copie
	ClapTrap& operator=(const ClapTrap& other);// Constructeur de copie.
	~ClapTrap(void);

	std::string getName() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

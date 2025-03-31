#ifndef SCRAV_TRAP_HPP
#define SCRAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(); // Constructeur par défaut.
    ScavTrap(std::string name);// Constructeur
    ScavTrap(const ScavTrap& copy);    // Constructeur de copie
    ~ScavTrap(void); //Destructeur
    ScavTrap& operator=(const ScavTrap& other);// A copy assignment operator overload.
    void guardGate();
    void attack(const std::string& target);
};

#endif


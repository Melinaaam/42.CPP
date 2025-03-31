#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(); // Constructeur par défaut.
    FragTrap(std::string name);// Constructeur
    FragTrap(const FragTrap& copy);    // Constructeur de copie
    ~FragTrap(void); //Destructeur
    FragTrap& operator=(const FragTrap& other);// A copy assignment operator overload.

    void highFivesGuys(void);
};

#endif
#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

// #include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _Name;
public:
    DiamondTrap(); // Constructeur par défaut.
    DiamondTrap(const std::string name);// Constructeur
    DiamondTrap(const DiamondTrap& copy);    // Constructeur de copie
    ~DiamondTrap(void); //Destructeur
    DiamondTrap& operator=(const DiamondTrap& other);// A copy assignment operator overload.

    using   ScavTrap::attack;
    void whoAmI();
};
#endif
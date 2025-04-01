#include"ScavTrap.hpp"
#include"ClapTrap.hpp"
#include"FragTrap.hpp"
#include"DiamondTrap.hpp"

int main()
{
    std::cout << "******* Test de DiamondTrap *******" << std::endl << std::endl;
    DiamondTrap Hera("Hera");
    std::cout << std::endl;
    Hera.attack("Aphrodyte");
    Hera.takeDamage(1);
    Hera.beRepaired(2);
    Hera.whoAmI();
    std::cout << std::endl;
    return 0;
}
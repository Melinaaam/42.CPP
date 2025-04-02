#include"ScavTrap.hpp"
#include"ClapTrap.hpp"
#include"FragTrap.hpp"
#include"DiamondTrap.hpp"

int main()
{
    std::cout << "******* Test de DiamondTrap *******" << std::endl << std::endl;
    std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
    DiamondTrap Hera("Hera");
    std::cout << std::endl;

    std::cout << "\033[38;5;220mInstances tests :\033[0m" << std::endl;
    Hera.attack("Aphrodyte");
    Hera.takeDamage(1);
    Hera.beRepaired(2);
    Hera.whoAmI();

    std::cout << std::endl;
    std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
    return 0;
}
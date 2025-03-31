#include"ScavTrap.hpp"
#include"ClapTrap.hpp"
#include"FragTrap.hpp"
#include"DiamondTrap.hpp"

int main()
{
    // std::cout << "******* Test de ClapTrap *******" << std::endl;
    // ClapTrap David("David");
    // ClapTrap Goliath("Goliath");
    // ClapTrap cpyGoliath(Goliath);
    // std::cout << std::endl;
    // David.attack("Goliath");
    // David.takeDamage(10);
    // David.beRepaired(5);
    // std::cout << std::endl;
        
    // std::cout << "******* Test de ScavTrap *******" << std::endl;
    // ScavTrap Zeus("Zeus");
    // ScavTrap Kronos("Kronos");
    // ClapTrap cpyKronos(Kronos);
    // std::cout << std::endl;
    // Zeus.attack("Kronos");
    // Kronos.takeDamage(20);
    // Kronos.beRepaired(10);
    // Zeus.guardGate();

    // std::cout << std::endl;

    // std::cout << "******* Test de FragTrap *******" << std::endl;
    // FragTrap Athena("Athena");
    // FragTrap Ulysse("Ulysse");
    // FragTrap cpyUlysse(Ulysse);
    // std::cout << std::endl;
    // Athena.attack("Ulysse");
    // Ulysse.takeDamage(20);
    // Ulysse.beRepaired(10);
    // Athena.highFivesGuys();

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
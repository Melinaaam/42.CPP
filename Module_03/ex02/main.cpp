#include"ScavTrap.hpp"
#include"ClapTrap.hpp"
#include"FragTrap.hpp"

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

    std::cout << "******* Test de FragTrap *******" << std::endl;
    std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
    FragTrap Athena("Athena");
    FragTrap Ulysse("Ulysse");
    std::cout << std::endl;

    std::cout << "\033[38;5;220mInstances tests :\033[0m" << std::endl;
    Athena.attack("Ulysse");
    Ulysse.takeDamage(20);
    Ulysse.beRepaired(10);
    Athena.highFivesGuys();

    std::cout << std::endl << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
    return 0;
}
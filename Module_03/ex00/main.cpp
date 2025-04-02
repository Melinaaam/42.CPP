#include"ClapTrap.hpp"

int main()
{
    std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
    ClapTrap David("David");
    ClapTrap Goliath("Goliath");
	std::cout << std::endl;

    std::cout << "\033[38;5;220mInstances tests :\033[0m" << std::endl;
    David.attack(Goliath.getName());
    Goliath.takeDamage(3);
    Goliath.beRepaired(5);

    for (int i = 0; i < 5; ++i){
        David.attack(Goliath.getName());
    }
    std::cout << std::endl;

    std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
    return 0;
}

#include"ClapTrap.hpp"

int main()
{
    ClapTrap David("David");
    ClapTrap Goliath("Goliath");
	ClapTrap cpyGoliath(Goliath);
	std::cout << std::endl;

    David.attack(Goliath.getName());
    Goliath.takeDamage(30);
    Goliath.beRepaired(5);

    for (int i = 0; i < 50; ++i){
        David.attack(Goliath.getName());
    }
    return 0;
}

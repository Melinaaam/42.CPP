#include"ClapTrap.hpp"

int main()
{
	ClapTrap First("David");
	ClapTrap second("Goliath");
	std::cout << "First claptrap name's : " << First.getName() << std::endl;
	std::cout << "Second claptrap name's : " << second.getName() << std::endl;
	First.attack(second.getName());
	second.beRepaired(1);
	return 0;
}

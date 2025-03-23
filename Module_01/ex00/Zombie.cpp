#include"Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << " Zombie " << name << " --> created." << std::endl << std::endl;
}
void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << " Zombie " << name << " --> destroyed" << std::endl << std::endl;
}

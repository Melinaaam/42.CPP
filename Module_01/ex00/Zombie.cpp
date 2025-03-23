#include"Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << name << "created." << std::endl;
}
void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << "destroyed" << std::endl;
}

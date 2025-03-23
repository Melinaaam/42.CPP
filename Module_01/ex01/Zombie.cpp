#include"Zombie.hpp"

Zombie::Zombie() : _name("")
{

}
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << name << " created " << std::endl;
}
void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setname(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " destroyed." << std::endl;
}

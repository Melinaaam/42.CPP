#include"Zombie.hpp"
//heap
Zombie* newZombie( std::string name )
{
	return new Zombie(name);
}

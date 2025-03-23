#include"Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("heapZombie");
	heapZombie->announce();

	delete heapZombie;

	randomChump("StackZombie");
	return 0;
}

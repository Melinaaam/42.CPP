#include"Zombie.hpp"

int main()
{
	Zombie *Zombie1 = newZombie("Zombie1 ");
	Zombie1->announce();

	Zombie *Zombie3 = newZombie("Zombie3 ");
	Zombie3->announce();

	randomChump("Zombie2");
	delete Zombie3;
	delete Zombie1;
	return 0;
}

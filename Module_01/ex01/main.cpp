#include"Zombie.hpp"

int main()
{
	int N = 10;

	Zombie *FirstHorde = zombieHorde(N, "FirstHorde");
	if (FirstHorde)
	{
		for (int i = 0; i < N; i++)
			FirstHorde[i].announce();
	delete []FirstHorde;
	}
	return 0;
}

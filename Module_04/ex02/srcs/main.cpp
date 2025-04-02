#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

/*
Différence entre virtual et virtual pure

virtual : Une fonction virtuelle peut avoir une implémentation dans la classe de base,
		mais elle peut être redéfinie dans les classes dérivées.
virtual pure : Une fonction virtuelle pure n'a pas d'implémentation dans la classe de base
			et doit être implémentée dans les classes dérivées. Elle est déclarée avec = 0.
*/
int main()
{
	const int n = 10;
    Animal* animals[n];

    std::cout << "\033[38;5;32mCreation of animals 🐾 :\033[0m" << std::endl;
    for (int i = 0; i < n / 2; ++i)
        animals[i] = new Dog();
    for (int i = n / 2; i < n; ++i)
        animals[i] = new Cat();

    std::cout << "\033[38;5;220mTypes and sounds of animals 🐾📢:\033[0m" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and he goes : ";
        animals[i]->makeSound();
    }

    std::cout << "\033[38;5;32mRemoval of animals 🗑️:\033[0m" << std::endl;
    for (int i = 0; i < n; ++i)
        delete animals[i];

    std::cout << "\033[38;5;32mDeep copy tests 🧐:\033[0m" << std::endl;
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << "Original Dog : ";
    originalDog->makeSound();
    std::cout << "Copied Dog : ";
    copiedDog->makeSound();

    delete originalDog;
    delete copiedDog;

    Cat* originalCat = new Cat();
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << "Original Cat : ";
    originalCat->makeSound();
    std::cout << "Copied Cat : ";
    copiedCat->makeSound();

    delete originalCat;
    delete copiedCat;

    return 0;
}

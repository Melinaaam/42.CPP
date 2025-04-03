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
    AAnimal* animals[n]; //creer un ptr d'animal OK
    // Animal* animal = new Animal(); mais une instance d'animal

    std::cout << CYAN << "Creation of animals 🐾 :" << RESET << std::endl;
    for (int i = 0; i < n / 2; ++i)
        animals[i] = new Dog();
    for (int i = n / 2; i < n; ++i)
        animals[i] = new Cat();

    std::cout << std::endl << YELLOW << "Types and sounds of animals 🐾📢:" << RESET << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and he goes : ";
        animals[i]->makeSound();
    }

    std::cout << std::endl << GREEN << "Removal of animals 🗑️:" << RESET << std::endl;
    for (int i = 0; i < n; ++i)
        delete animals[i];

    std::cout << std::endl << CYAN << "Deep copy tests 🧐:" << RESET << std::endl;
    std::cout << YELLOW << "Types and sounds of dogs📢:" << RESET << std::endl;
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << "Original Dog : ";
    originalDog->makeSound();
    std::cout << "Copied Dog : ";
    copiedDog->makeSound();

    std::cout << std::endl << GREEN << "Removal animals 🗑️:" << RESET << std::endl;
    delete originalDog;
    delete copiedDog;
    
    std::cout << std::endl << YELLOW << "Types and sounds of cats📢:" << RESET << std::endl;
    Cat* originalCat = new Cat();
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << "Original Cat : ";
    originalCat->makeSound();
    std::cout << "Copied Cat : ";
    copiedCat->makeSound();

    std::cout << std::endl << GREEN << "Removal of animals 🗑️:" << RESET << std::endl;
    delete originalCat;
    delete copiedCat;

    return 0;
}

#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"I

/*
Différence entre virtual et virtual pure

virtual : Une fonction virtuelle peut avoir une implémentation dans la classe de base,
		mais elle peut être redéfinie dans les classes dérivées.
virtual pure : Une fonction virtuelle pure n'a pas d'implémentation dans la classe de base
			et doit être implémentée dans les classes dérivées. Elle est déclarée avec = 0.
*/
int main()
{
    std::cout << CYAN << "First tests subject" << RESET << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	const AAnimal* newCat = new Cat(dynamic_cast<const Cat&>(*i));
	std::cout << std::endl << YELLOW << "Instances tests" << RESET << std::endl;
    std::cout << "j" << " is a " << j->getType() << " and he goes : ";
	j->makeSound();
	if (dynamic_cast<const Dog*>(j))
		dynamic_cast<const Dog*>(j)->getIdeas(0, 4);
    std::cout << "i" << " is a " << i->getType() << " and he goes : ";
    i->makeSound();
	if (dynamic_cast<const Cat*>(i))
		dynamic_cast<const Cat*>(i)->getIdeas(0, 4);
    std::cout << "newCat" << " is a " << newCat->getType() << " and he goes : ";
    newCat->makeSound();
	if (dynamic_cast<const Cat*>(newCat))
		dynamic_cast<const Cat*>(newCat)->getIdeas(2, 4);
    
    std::cout << std::endl << GREEN << "Removal 🗑️:" << RESET << std::endl;
	delete j;
	delete i;
	delete newCat;

    std::cout << std::endl << CYAN << "Creation of array's animals 🐾 :" << RESET << std::endl;
    std::cout << YELLOW << "Instances" << RESET << std::endl;
	const int Aarray = 10; //
    AAnimal* animals[Aarray]; //creer un ptr d'animal OK
    // Animal* animal = new Animal(); mais une instance d'animal
    
    std::cout<< YELLOW << "Size of animals's array is : " << RESET << Aarray << std::endl;
    std::cout << std::endl << YELLOW << "Types and sounds of animals 🐾📢:" << RESET << std::endl;
    for (int i = 0; i < Aarray / 2; ++i)
    animals[i] = new Dog();
    for (int i = Aarray / 2; i < Aarray; ++i)
    animals[i] = new Cat();

	std::cout << animals[Aarray / 2 - 1]->getType() << " -> ";
	animals[Aarray / 2 - 1]->makeSound();
    for (int i = 0; i < Aarray; ++i)
    {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and he goes : ";
        animals[i]->makeSound();
    }

	if (dynamic_cast<const Dog*>(animals[Aarray / 2 - 1]))
		dynamic_cast<const Dog*>(animals[Aarray / 2 - 1])->getIdeas(5, 1);

	if (dynamic_cast<const Cat*>(animals[Aarray / 2]))
		dynamic_cast<const Cat*>(animals[Aarray / 2])->getIdeas(4, 2);
    
    std::cout << std::endl << GREEN << "Removal of animals 🗑️🐾:" << RESET << std::endl;
	for (int i(0); i < Aarray; i++)
		delete animals[i];

    std::cout << std::endl << CYAN << "Deep copy tests 🧐:" << RESET << std::endl;
    std::cout << YELLOW << "Types and sounds of dogs📢:" << RESET << std::endl;
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << "Original Dog : ";
    originalDog->makeSound();
    originalDog->getIdeas(5, 1);
    std::cout << "Copied Dog : ";
    copiedDog->makeSound();
    copiedDog->getIdeas(5, 1);

    std::cout << std::endl << GREEN << "Removal animals 🗑️:" << RESET << std::endl;
    delete originalDog;
    delete copiedDog;
    
    std::cout << std::endl << YELLOW << "Types and sounds of cats📢:" << RESET << std::endl;
    Cat* originalCat = new Cat();
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << "Original Cat : ";
    originalCat->makeSound();
    originalCat->getIdeas(5, 1);
    std::cout << "Copied Cat : ";
    copiedCat->makeSound();
    copiedCat->getIdeas(5, 1);

    std::cout << std::endl << GREEN << "Removal of animals 🗑️:" << RESET << std::endl;
    delete originalCat;
    delete copiedCat;

    std::cout << std::endl << "\033[38;5;45mInstances copies tests\033[0m" << std::endl;
    return 0;
}


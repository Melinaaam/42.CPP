#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    const int n = 200;
    Animal* animals[n];

    std::cout << CYAN << "      Creation of animals 🐾 :" << RESET << std::endl;
    for (int i = 0; i < n / 2; ++i)
        animals[i] = new Dog();
    for (int i = n / 2; i < n; ++i)
        animals[i] = new Cat();

    std::cout << YELLOW << "        Types and sounds of animals 🐾📢:" << RESET << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and he goes : ";
        animals[i]->makeSound();
    }

    std::cout << std::endl << GREEN << "     Removal of animals 🗑️:" << RESET << std::endl;
    for (int i = 0; i < n; ++i)
        delete animals[i];

    std::cout <<  std::endl << CYAN << BOLD << "    Deep copy tests 🧐:" << RESET << std::endl;
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << std::endl << YELLOW << "Original Dog :" << RESET << " is a " << originalDog->getType() << " and he goes : ";
    originalDog->makeSound();
    std::cout << YELLOW << "Copied Dog :" << RESET << " is a " << originalDog->getType() << " and he goes : ";
    copiedDog->makeSound();

    std::cout << std::endl << GREEN << "     Removal of animals 🗑️:" << RESET << std::endl;
    delete originalDog;
    delete copiedDog;

    Cat* originalCat = new Cat();
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << std::endl << YELLOW << "Original Cat :" << RESET << " is a " << originalDog->getType() << " and he goes : ";
    originalCat->makeSound();
    std::cout << YELLOW << "Copied Cat :" << RESET << " is a " << originalDog->getType() << " and he goes : ";
    copiedCat->makeSound();

    std::cout << std::endl << GREEN << "     Removal of animals 🗑️:" << RESET << std::endl;
    delete originalCat;
    delete copiedCat;

    return 0;
}

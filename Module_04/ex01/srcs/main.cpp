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
    
    std::cout << CYAN << "      Creation of array's animals 🐾 :" << RESET << std::endl;
    const int n = 10;
    Animal* Aarray[n];
    for (int i = 0; i < n / 2; ++i)
        Aarray[i] = new Dog();
    for (int i = n / 2; i < n; ++i)
        Aarray[i] = new Cat();

    std::cout << YELLOW << "        Types and sounds of animals 🐾📢:" << RESET << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Animal " << i << " is a " << Aarray[i]->getType() << " and he goes : ";
        Aarray[i]->makeSound();
    }
 
    std::cout << std::endl << GREEN << "     Removal of animals 🗑️:" << RESET << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << std::endl;
        delete Aarray[i];
    }
    /**************************************************************************************** */
    std::cout << YELLOW << "        Ideas of animals 🐾📢:" << RESET << std::endl;
    const Animal* Mycat = new Cat();
    const Animal* Mydog = new Dog();

    std::cout << "Mycat" << " is a " << Mycat->getType() << " and he goes : ";
    Mycat->makeSound();
    std::cout << std::endl << MAGENTA << "Ideas of " << Mycat->getType() << " : " << RESET << std::endl;
    //Utilisation du dynamic cast car Mycat & Mydog sont decla comme ptr vers Animal, 
    //dc acces qu'aux methodes definies dans Animal, ici on vt faire appel a getIdeas, 
    //qui est spécifique à la classe Cat, on vcheck que l'objet référencé est bien un Cat.
    if(dynamic_cast<const Cat*>(Mycat))
        dynamic_cast<const Cat*>(Mycat)->getIdeas(2, 115);

    std::cout << "Mydog" << " is a " << Mydog->getType() << " and he goes : ";
    Mydog->makeSound();
    std::cout << std::endl << MAGENTA << "Ideas of " << Mydog->getType() << " : " << RESET << std::endl;
    if(dynamic_cast<const Dog*>(Mydog))
        dynamic_cast<const Dog*>(Mydog)->getIdeas(0, 4);

    std::cout << std::endl << GREEN << "     Removal of Mycat & My dog 🗑️:" << RESET << std::endl;
    delete Mycat;
    delete Mydog;
    /**************************************************************************************** */

    std::cout <<  std::endl << CYAN << BOLD << "    Deep copy tests 🧐:" << RESET << std::endl;
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << std::endl << YELLOW << "Original Dog :" << RESET << " is a " << originalDog->getType() << " and he goes : ";
    originalDog->makeSound();
    originalDog->getIdeas(2, 4);

    std::cout << YELLOW << "Copied Dog :" << RESET << " is a " << originalDog->getType() << " and he goes : ";
    copiedDog->makeSound();
    copiedDog->getIdeas(2, 4);

    std::cout << std::endl << GREEN << "     Removal of original & copy dog 🗑️:" << RESET << std::endl;
    delete originalDog;
    delete copiedDog;

    Cat* originalCat = new Cat();
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << std::endl << YELLOW << "Original Cat :" << RESET << " is a " << originalCat->getType() << " and he goes : ";
    originalCat->makeSound();
    std::cout << YELLOW << "Copied Cat :" << RESET << " is a " << originalCat->getType() << " and he goes : ";
    copiedCat->makeSound();

    std::cout << std::endl << GREEN << "     Removal of animals 🗑️:" << RESET << std::endl;
    delete originalCat;
    delete copiedCat;

    return 0;
}

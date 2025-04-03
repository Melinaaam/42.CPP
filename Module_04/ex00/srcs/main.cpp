#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    //....
    std::cout << "" << std::endl << PINK << "MY TESTS : " << RESET << std::endl;
    std::cout << CYAN << "Cat && Dog initialised by Cat && Dog : " << RESET << std::endl;
    const Animal* MyAnimal = new Animal;
    const Cat* MyCat = new Cat;
    const Dog* MyDog = new Dog;

    std::cout << std::endl;
    std::cout << YELLOW << "MyAnimal is a: " << RESET << MyAnimal->getType() << " and he goes : ";
    MyAnimal->makeSound();

    std::cout << YELLOW << "MyCat is a: " << RESET << MyCat->getType() << " and he goes : ";
    MyCat->makeSound();

    std::cout << YELLOW << "mMyDog is a: " << RESET << MyDog->getType() << " and he goes : ";
    MyDog->makeSound();

    std::cout << std::endl << CYAN << "Instances delete  : " << RESET << std::endl;
    delete MyAnimal;
    delete MyCat;
    delete MyDog;

    std::cout << std::endl << CYAN << "Cat && Dog initialised by Animal : " << RESET << std::endl;
    const Animal* AnimAnimal = new Animal;
    const Animal* AnimCat = new Cat;
    const Animal* AnimADog = new Dog;


    std::cout << std::endl << YELLOW << "AnimAnimal is a: " << RESET << AnimAnimal->getType() << " and he goes : ";
    AnimAnimal->makeSound();

    std::cout << YELLOW << "AnimCat is a: " << RESET << AnimCat->getType() << " and he goes : ";
    AnimCat->makeSound();

    std::cout << YELLOW << "AnimADog is a: " << RESET << AnimADog->getType() << " and he goes : ";
    AnimADog->makeSound();

    std::cout << std::endl << CYAN << "Instances delete  : "<< RESET << std::endl;
    delete AnimAnimal;
    delete AnimCat;
    delete AnimADog;

    std::cout << std::endl << CYAN << "Wrong Animals initialised : " << RESET << std::endl;
    const WrongAnimal* MyWrongAnimal = new WrongAnimal;
    const WrongCat* MyWrongCat = new WrongCat;

    std::cout << std::endl << YELLOW << "MyWrongAnimal is a: " << RESET << MyWrongAnimal->getType() << " and he goes : ";
    MyWrongAnimal->makeSound();

    std::cout << YELLOW << "WrongCat is a: " << RESET << MyWrongCat->getType() << " and he goes : ";
    MyWrongCat->makeSound();

	std::cout << std::endl << CYAN << "Wrong Cat initialised as WrongAnimal :" << RESET << std::endl;
	const WrongAnimal* WrongCatAsAnimal = new WrongCat;

	std::cout << YELLOW << " ***WrongCatAsAnimal*** is a: " << RESET << WrongCatAsAnimal->getType() << " and he goes : ";
	WrongCatAsAnimal->makeSound();  //devrait appeler la méthode de WrongAnimal, pas de WrongCat

	std::cout << std::endl << CYAN << "Instance delete :" << RESET << std::endl;
	delete WrongCatAsAnimal;
    delete MyWrongAnimal;
    delete MyWrongCat;

    return 0;
}

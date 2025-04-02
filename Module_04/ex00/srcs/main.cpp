#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     ...
//     return 0;
// }

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
    std::cout << "\033[38;5;213mMy tests :\033[0m" << std::endl;
    const Animal* MyAnimal = new Animal;
    const Cat* MyCat = new Cat;
    const Dog* MyDog = new Dog; 
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "\033[38;5;220mMyAnimal is a: \033[0m" << MyAnimal->getType() << " and it make : ";
    MyAnimal->makeSound();
    std::cout << "" << std::endl;
    
    std::cout << "\033[38;5;220mMyCat is a: \033[0m" << MyCat->getType() << " and it make : ";
    MyCat->makeSound();
    std::cout << "" << std::endl;
    
    std::cout << "\033[38;5;220mMyDog is a: \033[0m" << MyDog->getType() << " and it make : ";
    MyDog->makeSound();
    std::cout << "" << std::endl;

    delete MyAnimal;
    delete MyCat;
    delete MyDog;

    std::cout << "" << std::endl;
    std::cout << "\033[38;5;213mWrong Animals :\033[0m" << std::endl;
    const WrongAnimal* MyWrongAnimal = new WrongAnimal;
    const WrongCat* MyWrongCat = new WrongCat;

    std::cout << std::endl;
    std::cout << "\033[38;5;220mMyWrongAnimal is a: \033[0m" << MyWrongAnimal->getType() << " and it make : ";
    MyWrongAnimal->makeSound();
    std::cout << "" << std::endl;
    
    std::cout << "\033[38;5;220mMyWrongCat is a: \033[0m" << MyWrongCat->getType() << " and it make : ";
    MyWrongCat->makeSound();
    std::cout << "" << std::endl;
    
    std::cout << std::endl;
    std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;

    delete MyWrongAnimal;
    delete MyWrongCat;

    return 0;
}
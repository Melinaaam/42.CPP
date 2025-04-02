#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Brain.hpp"

int main()
{
    /*
    Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la
moitié est composée d’objets Dog et l’autre moitié d’objets Cat. À la fin de l’exécution
du programme, parcourez ce tableau afin de delete chaque Animal. Vous devez delete
directement les chiens et les chats en tant qu’Animal. Les destructeurs correspondants
doivent être appelés dans le bon ordre.
    */
    std::cout << "\033[38;5;213mTests :\033[0m" << std::endl;
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
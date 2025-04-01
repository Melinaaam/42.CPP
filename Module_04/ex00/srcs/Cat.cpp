#include"Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called !" << std::endl;
}
Cat::Cat(std::string name)
{
    name = "Cat";
    std::cout << "Cat constructor called !" << std::endl;
}
Cat::Cat(const Cat& copy)
{
    (void)copy;
    std::cout << "Cat copy constructor called !" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    (void)other;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat detructor called !" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "Waf Waf" << std::endl;
}
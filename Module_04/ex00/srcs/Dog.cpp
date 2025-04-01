#include"Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called !" << std::endl;
}
Dog::Dog(std::string name)
{
    name = "Dog";
    std::cout << "Dog constructor called !" << std::endl;
}
Dog::Dog(const Dog& copy)
{
    (void)copy;
    std::cout << "Dog copy constructor called !" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    (void)other;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << "Dog detructor called !" << std::endl;
}

void Dog::makeSound()
{
    std::cout << "Waf Waf" << std::endl;
}
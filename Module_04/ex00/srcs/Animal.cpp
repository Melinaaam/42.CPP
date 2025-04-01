#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal default constructor called !" << std::endl;
}
Animal::Animal(std::string newType) 
{
    std::cout << "Animal constructor called !" << std::endl;
    type = newType;
}
Animal::Animal(const Animal& copy)
{
    (void)copy;
    std::cout << "Animal copy constructor called !" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
    (void)other;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << "Animal detructor called !" << std::endl;
}

std::string Animal::getType() const { return this->type;}


void Animal::makeSound()
{
    std::cout << "Sound of Animal" << std::endl;
}
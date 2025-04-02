#include"Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << _type << " default constructor called !" << std::endl;
}
Dog::Dog(std::string Type)
{
    std::cout << _type << " constructor called !" << std::endl;
    *this = Type;
}
Dog::Dog(const Dog& copy)
{
    (void)copy;
    std::cout << _type << " copy constructor called !" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
        _type = other._type;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << _type << " detructor called !" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Waf Waf" << std::endl;
}
#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << _type << " default constructor called !" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
    std::cout << _type << " copy constructor called !" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
    if(this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << _type << " detructor called !" << std::endl;
}

std::string Animal::getType() const { return this->_type;}


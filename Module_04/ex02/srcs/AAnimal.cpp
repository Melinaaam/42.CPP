#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << _type << " default constructor called !" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	*this = copy;
    std::cout << _type << " copy constructor called !" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if(this != &other)
        _type = other._type;
    return *this;
}

AAnimal::~AAnimal(void)
{
    std::cout << _type << " detructor called !" << std::endl;
}

std::string AAnimal::getType() const { return this->_type;}


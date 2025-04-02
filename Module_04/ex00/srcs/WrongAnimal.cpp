#include"WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << _type << " default constructor called !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    _type = copy._type;
    std::cout << _type << " copy constructor called !" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << _type << " detructor called !" << std::endl;
}

std::string WrongAnimal::getType() const { return this->_type;}


void WrongAnimal::makeSound() const
{
        std::cout << "😼 Sound of " << _type << " 😼" << std::endl;
}

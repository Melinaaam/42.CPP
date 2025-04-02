#include"Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << _type << " default constructor called !" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    _type = copy._type;
    std::cout << _type << " copy constructor called !" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
	{
		Animal::operator=(other);
		_type = other._type;
	}
    return *this;
}

Dog::~Dog(void)
{
    std::cout << _type << " detructor called !" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶 Waf Waf 🐶" << std::endl;
}

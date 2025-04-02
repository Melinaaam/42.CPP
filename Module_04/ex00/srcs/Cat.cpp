#include"Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << _type << " default constructor called !" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    _type = copy._type;
    std::cout << _type << " copy constructor called !" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
	{
		Animal::operator=(other);
        _type = other._type;
	}
    return *this;
}

Cat::~Cat(void)
{
	std::cout << _type << " destructor called !" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐈 Miaou Miaou 🐈" << std::endl;
}

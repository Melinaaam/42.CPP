#include"Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << _type << " default constructor called !" << std::endl;
}
Cat::Cat(std::string name)
{
    std::cout << _type << " constructor called !" << std::endl;
    Animal::_type = name;
}

Cat::Cat(const Cat& copy)
{
    (void)copy;
    std::cout << _type << " copy constructor called !" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
        _type = other._type;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << _type << " detructor called !" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miaou Miaou" << std::endl;
}
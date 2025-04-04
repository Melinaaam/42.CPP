#include"WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called !" << std::endl;
}
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    (void)copy;
    std::cout << "WrongCat copy constructor called !" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this != &other)
	{
		WrongAnimal::operator=(other);
        _type = other._type;
	}
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat detructor called !" << std::endl;
}

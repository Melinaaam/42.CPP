#include"WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called !" << std::endl;
    // _type = "WrongCat";
}
WrongCat::WrongCat(std::string Type)
{
    std::cout << "WrongCat constructor called !" << std::endl;
    *this = Type;
}
WrongCat::WrongCat(const WrongCat& copy)
{
    (void)copy;
    std::cout << "WrongCat copy constructor called !" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this != &other)
        _type = other._type;
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat detructor called !" << std::endl;
}

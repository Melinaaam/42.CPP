#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;

}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Assignment operator called" << std::endl;
    if(this != &copy)
        this->_fixedValue = copy._fixedValue;
    return *this;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedValue;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixedValue = raw;
}
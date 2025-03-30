#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;

}

Fixed::Fixed(const int i)
{
    // std::cout << "Int constructor called" << std::endl;
    _fixedValue = i << _fractBits;
}
Fixed::Fixed(const float f)
{
    // std::cout << "Float constructor called" << std::endl;
    _fixedValue = static_cast<int>(round(f * (1 << _fractBits)));
}

Fixed::~Fixed()
{
    // std::cout << "destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    // std::cout << "Assignment operator called" << std::endl;
    if(this != &copy)
        this->_fixedValue = copy._fixedValue;
    return *this;
}

int Fixed::getRawBits( void ) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedValue;
}

void Fixed::setRawBits( int const raw ){
	// std::cout << "setRawBits member function called" << std::endl;
	_fixedValue = raw;
}

int Fixed::toInt( void ) const
{
    // Convertit la valeur fixe en entier (décalage à droite)
    return _fixedValue >> _fractBits;
}

float Fixed::toFloat( void ) const
{
    // Converla valeur fixe en float
    return static_cast<float>(_fixedValue) / (1 << _fractBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->_fixedValue > other._fixedValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_fixedValue < other._fixedValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_fixedValue >= other._fixedValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_fixedValue <= other._fixedValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_fixedValue == other._fixedValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedValue != other._fixedValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed temp;
	temp.setRawBits(this->_fixedValue + other._fixedValue);
	return temp;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed temp;
	temp.setRawBits(this->_fixedValue - other._fixedValue);
	return temp;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed temp;
    temp.setRawBits((this->_fixedValue * other._fixedValue) >> _fractBits);
    return temp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed temp;
	temp.setRawBits((this->_fixedValue << _fractBits) / other._fixedValue);
	return temp;
}

Fixed& Fixed::operator++()
{
	this->_fixedValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedValue += 1;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->_fixedValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedValue -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

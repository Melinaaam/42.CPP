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

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedValue = i << _fractBits;
}
Fixed::Fixed(const float f)
{
    // On convertit le flottant en valeur fixe en multipliant par 2^_fractBits, dc 2 puissance 8, soit 256
    // et en arrondissant au plus proche. (round) pour trouver l'arrondi,prend un float en param
    std::cout << "Float constructor called" << std::endl;
    _fixedValue = (round(f * (1 << _fractBits)));
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

int Fixed::toInt( void ) const
{
    // Convertit la valeur fixe en entier (décalage à droite)
    return _fixedValue >> _fractBits;
}

float Fixed::toFloat( void ) const
{
    // Converla valeur fixe en float en divisant par 2^_fractBits, dc 2 puissance 8, soit 256
    return static_cast<float>(_fixedValue) / (1 << _fractBits);
}


// Surcharge de l’opérateur d’insertion (<<)
// Affiche la représentation en virgule flottante
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat(); //pour afficher en float
    return out;
}

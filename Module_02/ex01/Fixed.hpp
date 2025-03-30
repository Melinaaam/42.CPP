#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>
#include<string>
#include<cmath>

class Fixed{
private:
    int _fixedValue; 
    static int const _fractBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed& copy);
    Fixed(const int i);
    Fixed(const float f);
    Fixed& operator=(const Fixed& copy);
    ~Fixed(void);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int toInt( void ) const;
    float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
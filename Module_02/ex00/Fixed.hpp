#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>
#include<string>

class Fixed{
private:
    int _fixedValue; 
    static int const _fractBits = 8;

public:
    //A default constructor : 
    Fixed(void);
    //A copy constructor :
    Fixed(const Fixed& copy);
    //A copy assignment operator overload :
    Fixed& operator=(const Fixed& copy);
    //A destructor
    ~Fixed(void);
        
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
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
	~Fixed(void);
	Fixed& operator=(const Fixed& copy);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
	//6 operator comparaison :
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	//4 arithmetic operators : 
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	//pre-incr/ post-incr/ pre-decre/ post-decre:
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif

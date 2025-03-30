#ifndef POINT_HPP
#define POINT_HPP
#include"Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
	//.....

public:
	Point(); // Constructeur par défaut qui initialise x et y à 0.
	Point(const float a, const float b);// Constructeur paramétré qui initialise x et y aux valeurs fournies.
	Point(const Point& copy);    // Constructeur de copie
	Point& operator=(const Point& other);// A copy assignment operator overload.
	~Point(void);

	Fixed getX() const;
	Fixed getY() const;
	//.......
};

#endif

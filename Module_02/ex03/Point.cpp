#include"Point.hpp"

Point::Point(): _x(0), _y(0)//A constructor that takes two constant floating-point numbers as parameters. It initializes x and y with those parameters.
{

}

Point::Point(const float a, const float b): _x(a), _y(b)
{

}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) // Constructeur de copie
{

}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point(void)
{

}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

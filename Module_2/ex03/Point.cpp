#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point(void) {}

Point &Point::operator=(const Point &other ) {
	(void)other;
	return *this;
}

Fixed	Point::getX(void) const{
	return x;
}
Fixed	Point::getY(void) const{
	return y;
}

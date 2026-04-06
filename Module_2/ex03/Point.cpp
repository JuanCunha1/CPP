#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other ) {
	(void)other;
	return *this;
}

Fixed	Point::getX() const{
	return this->x;
}
Fixed	Point::getY() const{
	return this->y;
}

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
private:
	const Fixed x;
	const Fixed y;

public:
	Point(void);
	Point(const Fixed x, const Fixed y);
	Point &operator=(const Point &other );
	Point(const Point& other);
	~Point(void);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};
#endif

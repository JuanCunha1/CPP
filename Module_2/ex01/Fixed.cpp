#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) : rawBits(value) {
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->rawBits = other.getRawBits();
	}
    return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void	Fixed::setRawBits(const int raw) {
	rawBits = raw;
}

int	Fixed::toInt( void ) const {
	return this->rawBits >> _fractionalBits;
}

float	Fixed::toFloat( void ) const {
	return (float)this->rawBits / (float)(1 << _fractionalBits);
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}

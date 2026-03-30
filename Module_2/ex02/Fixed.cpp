#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : rawBits(0) {
}

Fixed::Fixed(const int value) {
	this->rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) : rawBits(value) {
	this->rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->rawBits = other.getRawBits();
	}
    return *this;
}

Fixed::~Fixed() {
//	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
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

Fixed	Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool	Fixed::operator<(Fixed const &rhs) const {
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(Fixed const &rhs) const {
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &rhs) const {
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
}

Fixed&	Fixed::operator++() {
	this->rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	this->rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	operator--();
	return tmp;
}

Fixed &	Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}

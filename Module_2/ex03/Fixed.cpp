#include "Fixed.hpp"

/*                                CONSTRUCTORS                                */

Fixed::Fixed(void) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/*                             ASSIGNMENT OPERATOR                            */

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		rawBits = other.rawBits;

    return *this;
}

/*                               GETTERS/SETTERS                              */
int	Fixed::getRawBits() const {
	return rawBits;
}

void	Fixed::setRawBits(const int raw) {
	rawBits = raw;
}

/*                           CONVERSION FUNCTIONS                             */

int	Fixed::toInt( void ) const {
	return rawBits >> _fractionalBits;
}

float	Fixed::toFloat( void ) const {
	return (float)rawBits / (float)(1 << _fractionalBits);
}

/*                          COMPARISON OPERATORS                              */

bool	Fixed::operator<(Fixed const &rhs) const {
	return rawBits < rhs.rawBits;
}

bool	Fixed::operator>(Fixed const &rhs) const {
	return rawBits > rhs.rawBits;
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	return rawBits <= rhs.rawBits;
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	return rawBits >= rhs.rawBits;
}

bool	Fixed::operator==(Fixed const &rhs) const {
	return rawBits == rhs.rawBits;
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	return rawBits != rhs.rawBits;
}

/*                           ARITHMETIC OPERATORS                             */

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
	if (rhs.rawBits == 0) {
		std::cerr << "Error: division by zero" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

/*                         INCREMENT / DECREMENT                              */

Fixed&	Fixed::operator++(void) {
	rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	++rawBits;
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	--rawBits;
	return tmp;
}

/*                               MIN / MAX                                    */

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

/*                          STREAM INSERTION                                  */

std::ostream&	operator<<(std::ostream& o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}

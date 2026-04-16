#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {

private:
	int					rawBits;
	static const int	_fractionalBits = 8;

public:

	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed(void);

	Fixed 			&operator=(const Fixed &other);
	Fixed			operator+(Fixed const &rhs) const;
	Fixed			operator-(Fixed const &rhs) const;
	Fixed			operator*(Fixed const &rhs) const;
	Fixed			operator/(Fixed const &rhs) const;
	bool			operator<(Fixed const &rhs) const;
	bool			operator>(Fixed const &rhs) const;
	bool			operator<=(Fixed const &rhs) const;
	bool			operator>=(Fixed const &rhs) const;
	bool			operator==(Fixed const &rhs) const;
	bool			operator!=(Fixed const &rhs) const;
	Fixed&			operator++(void);
	Fixed			operator++(int);
	Fixed&			operator--(void);
	Fixed			operator--(int);

	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;

	static Fixed &			min(Fixed &a, Fixed &b);
	static Fixed const &	min(Fixed const &a, Fixed const &b);
	static Fixed &			max(Fixed &a, Fixed &b);
	static Fixed const &	max(Fixed const &a, Fixed const &b);
};

std::ostream&	operator<<(std::ostream& o, Fixed const &rhs);

#endif

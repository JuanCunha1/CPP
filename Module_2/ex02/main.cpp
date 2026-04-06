#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "+ operator : " << (b + d) << std::endl;
		std::cout << "- operator : " << (b - c) << std::endl;
		std::cout << "* operator : " << (b * c) << std::endl;
		std::cout << "/ operator : " << (b / c) << std::endl;

		if (b < c)
			std::cout << "b lower than c" << std::endl;
		else if (c > b)
			std::cout << "c greater than b" << std::endl;
		if (b == d)
			std::cout << "b equal d" << std::endl;
		else if (b != a)
			std::cout << "b different d" << std::endl;
		if (b >= d)
			std::cout << "b greater or equal d" << std::endl;
		if (b <= d)
			std::cout << "b lower or equal d" << std::endl;
		std::cout << a << " " << ++a << std::endl;
		std::cout << "min between:" << b << " and " << c << " is " << Fixed::min(b, c) << std::endl;
		std::cout << "max between:" << b << " and " << c << " is " << Fixed::max(b, c) << std::endl;
	}
	return 0;
}

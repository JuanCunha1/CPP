#include "whatever.hpp"
#include <iostream>

int main() {
	{
		std::cout << "------------------SUBJECT TESTS------------------" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "------------------TEST WITH INTEGERS------------------" << std::endl;
		int a = 651;
		int b = 6;
		int c = ::min(a, b);
		int d = ::max(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << c << std::endl;
		std::cout << "max(a, b) = " << d << std::endl;

		std::cout << "------------------TEST WITH INTEGERS AFTER SWAP------------------" << std::endl;
		::swap(a, b);
		c = ::min(a, b);
		d = ::max(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << c << std::endl;
		std::cout << "max(a, b) = " << d << std::endl;

		std::cout << "------------------TEST WITH FLOATS------------------" << std::endl;
		float e = 3.14f;
		float f = 2.71f;
		float g = ::min(e, f);
		float h = ::max(e, f);
		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "min(e, f) = " << g << std::endl;
		std::cout << "max(e, f) = " << h << std::endl;

		std::cout << "------------------TEST WITH STRINGS------------------" << std::endl;
		std::string i = "Hello";
		std::string j = "World";
		std::string k = ::min(i, j);
		std::string l = ::max(i, j);
		std::cout << "i = " << i << ", j = " << j << std::endl;
		std::cout << "min(i, j) = " << k << std::endl;
		std::cout << "max(i, j) = " << l << std::endl;

		std::cout << "------------------TEST WITH CHARACTERS------------------" << std::endl;
		char m = 'A';
		char n = 'B';
		char o = ::min(m, n);
		char p = ::max(m, n);
		std::cout << "m = " << m << ", n = " << n << std::endl;
		std::cout << "min(m, n) = " << o << std::endl;
		std::cout << "max(m, n) = " << p << std::endl;
	}

	return 0;
}

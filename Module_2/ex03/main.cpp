#include <iostream>
#include "Point.hpp"

// Forward declaration
bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point a, Point b, Point c, Point p, std::string name)
{
	std::cout << name << ": ";
	if (bsp(a, b, c, p))
		std::cout << "Inside ✅";
	else
		std::cout << "Outside ❌";
	std::cout << std::endl;
}

int main(void)
{
	// Triangle
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(10), Fixed(0));
	Point c(Fixed(0), Fixed(10));

	std::cout << "=== BSP TESTS ===" << std::endl;

	// ✅ Inside
	test(a, b, c, Point(Fixed(3), Fixed(3)), "Inside (3,3)");

	// ❌ Outside
	test(a, b, c, Point(Fixed(10), Fixed(10)), "Outside (10,10)");

	// ❌ On edge AB
	test(a, b, c, Point(Fixed(5), Fixed(0)), "On edge AB (5,0)");

	// ❌ On edge BC
	test(a, b, c, Point(Fixed(5), Fixed(5)), "On edge BC (5,5)");

	// ❌ On edge CA
	test(a, b, c, Point(Fixed(0), Fixed(5)), "On edge CA (0,5)");

	// ❌ On vertex A
	test(a, b, c, Point(Fixed(0), Fixed(0)), "On vertex A");

	// ❌ On vertex B
	test(a, b, c, Point(Fixed(10), Fixed(0)), "On vertex B");

	// ❌ On vertex C
	test(a, b, c, Point(Fixed(0), Fixed(10)), "On vertex C");

	// ✅ Another inside test
	test(a, b, c, Point(Fixed(1), Fixed(1)), "Inside (1,1)");

	// ❌ Clearly outside
	test(a, b, c, Point(Fixed(-1), Fixed(-1)), "Outside (-1,-1)");

	return 0;
}

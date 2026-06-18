#include "Span.hpp"
#include <ctime>   // time

int main() {
	srand(time(NULL));
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span sp(20000);

		std::vector<int> numbers;
		numbers.reserve(20000);

		for (int i = 1; i <= 1000000; ++i)
			numbers.push_back(i);

		std::random_shuffle(numbers.begin(), numbers.end());
		numbers.resize(20000);
		sp.addNumbers(numbers.begin(), numbers.end());

		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::vector<int> tmp = numbers;
		std::sort(tmp.begin(), tmp.end());

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

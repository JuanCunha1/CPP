#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <limits>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_numbers;

		Span(void);

	public:
		
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		Span(unsigned int N);

		int		shortestSpan() const;
		int		longestSpan() const;
		void	addNumber(int number);

		class maxCapacityException : public std::exception {
			const char *what() const throw();
		};
		class noSpanFound : public std::exception {
			const char *what() const throw();
		};

};

#endif // SPAN_HPP

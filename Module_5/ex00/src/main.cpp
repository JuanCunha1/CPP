#include "Bureaucrat.hpp"

int main() {
	{
		try {
			Bureaucrat b("Bob", 151);
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat c("Cal", 0);
			std::cout << c << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
	{
		try {
			Bureaucrat b("Bob", 15);
			Bureaucrat c("Cal", 150);
			Bureaucrat d("clin", 1);
			b.incrementGrade();
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
			c.incrementGrade();
			std::cout << c << std::endl;
			c.decrementGrade();
			c.decrementGrade();
			std::cout << c << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

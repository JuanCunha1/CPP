#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	std::cout << "===== SUCCESS TEST =====" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 10);
		Form permit("Building Permit", 20, 5);

		alice.signForm(permit);

		std::cout << permit << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "===== FAILURE TEST =====" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 100);
		Form secret("Top Secret Form", 50, 10);

		bob.signForm(secret);

		std::cout << secret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "===== INVALID FORM TEST =====" << std::endl;

	try
	{
		Form invalid("Invalid", 0, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

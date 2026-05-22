#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	void	incrementGrade();
	void	decrementGrade();
	const std::string	getName() const;
	int	getGrade() const;

private:
	const std::string	name;
	int					grade;
};
std::ostream&	operator<<(std::ostream& o, Bureaucrat const &bur);
#endif // BUREAUCRAT_HPP

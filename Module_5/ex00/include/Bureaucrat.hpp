#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string& name, int grade);

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		void				incrementGrade();
		void				decrementGrade();
		const std::string&	getName() const;
		int					getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};
std::ostream&	operator<<(std::ostream& o, Bureaucrat const &bur);
#endif // BUREAUCRAT_HPP

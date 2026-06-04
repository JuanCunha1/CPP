#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		void				signForm(AForm &Form) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void				beSigned(const Bureaucrat &bureaucrat);
		void 				executeForm(AForm const & form) const;

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

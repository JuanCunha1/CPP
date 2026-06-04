#ifndef AAForm_HPP
#define AAForm_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		// Orthodox Canonical AForm
		AForm(void);
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;


		void		setSigned(bool sig);
		void		beSigned(const Bureaucrat &bureaucrat);

		void execute(Bureaucrat const &executor) const;
		virtual void executer() const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormIsNotSigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const AForm &Form);

#endif // AForm_HPP

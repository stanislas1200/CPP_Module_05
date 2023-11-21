#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>

class Bureaucrat;

class AForm {
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
	public:
		AForm();
		AForm(AForm const & src);
		virtual ~AForm();
		AForm & operator=(AForm const & src);

		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);

		std::string const getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat & src);
		virtual void execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& src);
#endif
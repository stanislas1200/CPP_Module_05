#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

# define RED "\x1b[1m\x1b[38;2;255;0;0m"
# define MB "\x1b[1m\x1b[38;2;25;25;599m"
# define GREEN "\x1b[1m\x1b[38;2;0;128;0m"
# define YELLOW "\x1b[1m\x1b[38;2;255;255;0m"
# define C "\x1b[0m"

class Bureaucrat {
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & src);

		Bureaucrat(std::string const name, int grade);

		std::string const getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);
#endif
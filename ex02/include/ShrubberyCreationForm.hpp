#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		std::string const target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

		ShrubberyCreationForm(std::string target);

		void execute(Bureaucrat const & executor) const;
};

#endif
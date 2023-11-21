#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class BureauCrat;

class PresidentialPardonForm : public AForm {
	private:
		std::string const target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

		PresidentialPardonForm(std::string target);

		void execute(Bureaucrat const & executor) const;
};

#endif
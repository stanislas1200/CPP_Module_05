#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		std::string const target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

		RobotomyRequestForm(std::string target);

		void execute(Bureaucrat const & executor) const;
};

#endif 
#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

static AForm * CRRF(std::string const & target) {
	return new RobotomyRequestForm(target);
}

static AForm * CPPF(std::string const & target) {
	return new PresidentialPardonForm(target);
}

static AForm * CSCF(std::string const & target) {
	return new ShrubberyCreationForm(target);
}

Intern::Intern() {
	formMap["robotomy request"] = &CRRF;
	formMap["presidential pardon"] = &CPPF;
	formMap["shrubbery creation"] = &CSCF;
}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & src) {
	(void)src;
	return *this;
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target) const {
	if (formMap.find(formName) != formMap.end()) {
		std::cout << "Intern creates " << formName << std::endl;
		return static_cast<AForm*>(formMap.at(formName)(target));
	}
	else {
		std::cout << "Intern cannot create " << formName << " because it is an unknown form" << std::endl;
		return NULL;
	}
}
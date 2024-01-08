#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int	main()
{
	std::srand(std::time(NULL));
	
	Bureaucrat b("Bender", 5);
	Intern someRandomIntern;
	AForm* rrf;

	std::cout << b << std::endl;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *rrf;
	rrf->beSigned(b);
	std::cout << *rrf;
	rrf->execute(b);
	std::cout << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;
	rrf->beSigned(b);
	std::cout << *rrf;
	rrf->execute(b);
	std::cout << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *rrf;
	rrf->beSigned(b);
	std::cout << *rrf;
	rrf->execute(b);
	std::cout << std::endl;
	delete rrf;	
}
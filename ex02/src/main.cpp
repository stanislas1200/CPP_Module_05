#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <unistd.h>
#include <cmath>

// void	makeFormTest(std::string const name, int const gradeToSign, int const gradeToExecute, Bureaucrat * b)
// {
// 	try {
// 		Form f(name, gradeToSign, gradeToExecute);
// 		std::cout << f;
// 		f.beSigned(*b);
// 		std::cout << f;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }

int	main()
{
	std::srand(std::time(NULL));

	Bureaucrat * b = new Bureaucrat("Bob", 5);
	ShrubberyCreationForm * s = new ShrubberyCreationForm("home");
	RobotomyRequestForm * r = new RobotomyRequestForm("home");
	PresidentialPardonForm * f = new PresidentialPardonForm("home");

	std::cout << "Trying to execute a Form not signed..." << std::endl;
	std::cout << *f;
	try {
		f->execute(*b);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Trying to execute a Form signed..." << std::endl;
	try {
		f->beSigned(*b);
		std::cout << *f;
		std::cout << *b;
		f->execute(*b);
		std::cout << std::endl;
		
		r->beSigned(*b);
		std::cout << *r;
		std::cout << *b;
		r->execute(*b);
		std::cout << std::endl;
		
		s->beSigned(*b);
		std::cout << *s;
		std::cout << *b;
		s->execute(*b);
		std::cout << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Trying to execute a Form with a grade too low..." << std::endl;
	try {
		b->decrementGrade();
		std::cout << *b;
		std::cout << *f;
		f->execute(*b);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete b;
	delete f;
	delete s;
	delete r;
}
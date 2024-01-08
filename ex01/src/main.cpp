#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <unistd.h>
#include <cmath>

void	makeFormTest(std::string const name, int const gradeToSign, int const gradeToExecute, Bureaucrat * b)
{
	try {
		Form f(name, gradeToSign, gradeToExecute);
		std::cout << f;
		f.beSigned(*b);
		std::cout << f;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int	main()
{
	Bureaucrat * b = new Bureaucrat("Bob", 42);
	std::cout << "Trying to create a Form with a grade too high..." << std::endl;
	makeFormTest("Form1", 0, 1, b);
	makeFormTest("Form1", 1, 0, b);
	std::cout << std::endl;

	std::cout << "Trying to create a bureaucrat with a grade too low..." << std::endl;
	makeFormTest("Form2", 151, 150, b);
	makeFormTest("Form2", 150, 151, b);
	std::cout << std::endl;

	std::cout << "Copy test:" << std::endl;
	try {
		Form f("Form3", 42, 41);
		Form f2(f);
		std::cout << f;
		std::cout << f2;
		f.beSigned(*b);
		std::cout << f;
		std::cout << f2;
		std::cout << "\nDouble sign test:" << std::endl;
		f.beSigned(*b);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Too Low grade test:" << std::endl;
	makeFormTest("Form4", 19, 42, b);
	delete b;
}
#include "../include/Bureaucrat.hpp"
#include <unistd.h>
#include <cmath>

void rgb(int r, int g, int b)
{
	std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << std::flush;
}

void setRainbowColor(int index) {
    const double frequency = 0.1;
    int r = sin(frequency * index + 0) * 127 + 128;
    int g = sin(frequency * index + 2) * 127 + 128;
    int b = sin(frequency * index + 4) * 127 + 128;

    std::cout << "\x1b[1m\x1b[38;2;" << r << ";" << g << ";" << b << "m" << std::flush;
}

void	updateGradeTest(int grade, void (Bureaucrat::*f)())
{
	try {
		Bureaucrat b("Bob", grade);
		std::cout << b;
		(b.*f)();
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	try { // increment / decrement
		Bureaucrat b("Bob", 42);
		unsigned int microsecond = 1000000;
		for (int i = 0; i < 23; i++)
		{
			b.incrementGrade();
			std::cout << "\x1b[H\x1b[2J";
			std::cout << "Incrementing grade..." << std::endl;
			setRainbowColor(i);
			std::cout << b;
			usleep(0.1 * microsecond);
		}
		for (int i = 0; i < 23; i++)
		{
			b.decrementGrade();
			std::cout << "\x1b[H\x1b[2J";
			if (i != 22)
			{
				std::cout << "Decrementing grade..." << std::endl;
				setRainbowColor(i);
			}
			else
				std::cout << "Incrementing / Decrementing test done!" << std::endl;
			std::cout << b;
			usleep(0.1 * microsecond);
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Trying to create a bureaucrat with a grade too high..." << std::endl;
	updateGradeTest(0, &Bureaucrat::incrementGrade);

	std::cout << "Trying to increment a bureaucrat with a grade too high..." << std::endl;
	updateGradeTest(1, &Bureaucrat::incrementGrade);

	std::cout << "Trying to create a bureaucrat with a grade too low..." << std::endl;
	updateGradeTest(151, &Bureaucrat::decrementGrade);

	std::cout << "Trying to decrement a bureaucrat with a grade too low..." << std::endl;
	updateGradeTest(150, &Bureaucrat::decrementGrade);

	std::cout << "Copy test:" << std::endl;
	try { // copy
		Bureaucrat b("Bob", 42);
		Bureaucrat c(b);
		std::cout << b;
		std::cout << c;
		std::cout << "Increment b" << std::endl;
		b.incrementGrade();
		std::cout << b;
		std::cout << c;
		std::cout << "c = b" << std::endl;
		c = b;
		std::cout << b;
		std::cout << c;
		std::cout << "Increment b" << std::endl;
		b.incrementGrade();
		std::cout << b;
		std::cout << c;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;

	}
}
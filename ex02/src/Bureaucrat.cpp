#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
	if (this != &src)
		grade = src.grade;
	return *this;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

std::string const Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return RED "Error" C ": " YELLOW "Grade too high" C;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return RED "Error" C ": " YELLOW "Grade too low" C;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src){
	os << src.getName() << C "," MB " bureaucrat grade " GREEN << src.getGrade() << C << std::endl;
	return os;
}

void Bureaucrat::signForm(Form & src) {
	if (src.getIsSigned())
		std::cout << DV << this->getName() << MB " signed " DV << src.getName() << C << std::endl;
	else
		std::cout << DV << this->getName() << MB " couldn’t sign " DV << src.getName() << MB " because " << YELLOW "grade is too low" C << std::endl;
}
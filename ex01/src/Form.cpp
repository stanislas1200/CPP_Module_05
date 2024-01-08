#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(Form const & src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {}

Form::~Form() {}

Form & Form::operator=(Form const & src) {
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

std::string const Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat & src) {
	if (this->isSigned)
		throw Form::AlreadySigned();
	else if (src.getGrade() > this->gradeToSign)
	{
		src.signForm(*this);	
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
	src.signForm(*this);
}


const char* Form::GradeTooHighException::what() const throw() {
	return RED "Error" C ": " YELLOW "Grade too high" C;
}

const char* Form::GradeTooLowException::what() const throw() {
	return RED "Error" C ": " YELLOW "Grade too low" C;
}

const char* Form::AlreadySigned::what() const throw() {
	return RED "Error" C ": " YELLOW "Form already signed" C;
}

std::ostream& operator<<(std::ostream& os, const Form& src) {
	os << MB "Form " DV << src.getName() << MB " is ";
	if (!src.getIsSigned())
		os << "not ";
	os << "signed, grade to sign: " GREEN << src.getGradeToSign() << MB ", grade to execute: " GREEN << src.getGradeToExecute() << C << std::endl;
	return os;
}
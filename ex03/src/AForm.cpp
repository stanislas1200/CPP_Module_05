#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(AForm const & src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & src) {
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

std::string const AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat & src) {
	if (this->isSigned)
		throw AForm::AlreadySigned();
	else if (src.getGrade() > this->gradeToSign)
	{
		src.signForm(*this);	
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
	src.signForm(*this);
}


const char* AForm::GradeTooHighException::what() const throw() {
	return RED "Error" C ": " YELLOW "Grade too high" C;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return RED "Error" C ": " YELLOW "Grade too low" C;
}

const char* AForm::NotSignedException::what() const throw() {
	return RED "Error" C ": " YELLOW "Form not signed" C;
}

const char* AForm::AlreadySigned::what() const throw() {
	return RED "Error" C ": " YELLOW "Form already signed" C;
}

std::ostream& operator<<(std::ostream& os, const AForm& src) {
	os << MB "AForm " DV << src.getName() << MB " is ";
	if (!src.getIsSigned())
		os << "not ";
	os << "signed, grade to sign: " GREEN << src.getGradeToSign() << MB ", grade to execute: " GREEN << src.getGradeToExecute() << C << std::endl;
	return os;
}
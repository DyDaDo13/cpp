/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:19:40 by dylmarti          #+#    #+#             */
/*   Updated: 2024/05/06 21:21:26 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeForSignature(150), _gradeForExecution(150) {
	std::cout << std::endl << "\e[32mForm constructor called for \e[0m" << this->getName() << std::endl
	<< "With theses grades: " << std::endl
	<< "\e[33m| GradeForSignature: \e[0m" << this->getGradeForSignature() << std::endl
	<< "\e[33m| GradeForExecution: \e[0m" << this->getGradeForExecution() << std::endl
	<< "\e[33m| Signed: \e[0m";
	if (this->getSignedValue() == true)
		std::cout << "True";
	else
		std::cout << "False";
	std::cout << std::endl << std::endl;
}

AForm::AForm(std::string name): _name(name), _signed(false), _gradeForSignature(150), _gradeForExecution(150) {
	std::cout << std::endl << "\e[32mForm constructor called for \e[0m" << this->getName() << std::endl
	<< "With theses grades: " << std::endl
	<< "\e[33m| GradeForSignature: \e[0m" << this->getGradeForSignature() << std::endl
	<< "\e[33m| GradeForExecution: \e[0m" << this->getGradeForExecution() << std::endl
	<< "\e[33m| Signed: \e[0m";
	if (this->getSignedValue() == true)
		std::cout << "True";
	else
		std::cout << "False";
	std::cout << std::endl << std::endl;
}

AForm::AForm(size_t gradeForSignature, size_t gradeForExecution): _name("default"), _signed(false) {
	if (gradeForExecution > 150 || gradeForSignature > 150)
		throw AForm::GradeTooLowException();
	else if (gradeForExecution < 1 || gradeForSignature < 1)
		throw AForm::GradeTooHighException();
	else {
		this->_gradeForExecution = gradeForExecution;
		this->_gradeForSignature = gradeForSignature;
		std::cout << std::endl << "\e[32mForm constructor called for \e[0m" << this->getName() << std::endl
		<< "With theses grades: " << std::endl
		<< "\e[33m| GradeForSignature: \e[0m" << this->getGradeForSignature() << std::endl
		<< "\e[33m| GradeForExecution: \e[0m" << this->getGradeForExecution() << std::endl
		<< "\e[33m| Signed: \e[0m";
		if (this->getSignedValue() == true)
			std::cout << "True";
		else
			std::cout << "False";
		std::cout << std::endl << std::endl;
	}
}

AForm::AForm(std::string name, size_t gradeForSignature, size_t gradeForExecution): _name(name), _signed(false) {
	if (gradeForExecution > 150 || gradeForSignature > 150)
		throw AForm::GradeTooLowException();
	else if (gradeForExecution < 1 || gradeForSignature < 1)
		throw AForm::GradeTooHighException();
	else {
		this->_gradeForExecution = gradeForExecution;
		this->_gradeForSignature = gradeForSignature;
		std::cout << std::endl << "\e[32mForm constructor called for \e[0m" << this->getName() << std::endl
		<< "With theses grades: " << std::endl
		<< "\e[33m| GradeForSignature: \e[0m" << this->getGradeForSignature() << std::endl
		<< "\e[33m| GradeForExecution: \e[0m" << this->getGradeForExecution() << std::endl
		<< "\e[33m| Signed: \e[0m";
		if (this->getSignedValue() == true)
			std::cout << "True";
		else
			std::cout << "False";
		std::cout << std::endl << std::endl;
	}
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(AForm const &cpy) {
	std::cout << "Form cpy constructor called" << std::endl;
	*this = cpy;
}

AForm &AForm::operator=(AForm const &n) {
	std::cout << "Form assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}

std::string	AForm::getName(void) const {
	return this->_name;
}

size_t			AForm::getGradeForSignature() const {
	return this->_gradeForSignature;
}

size_t			AForm::getGradeForExecution() const {
	return this->_gradeForExecution;
}

bool		AForm::getSignedValue() const {
	if (this->_signed == true)
		return true;
	return false;
}

void		AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeForSignature())
		throw AForm::GradeTooLowException();
	else if (this->_signed == false){
		this->_signed = true;
		std::cout << this->getName() << " Signed by " << bureaucrat.getName() << std::endl;
	}
	else {
		std::cout << this->getName() << " cannot signed, already signed !" << std::endl;
	}
}

void AForm::execute(Bureaucrat const &executor)const
{
	(void)executor;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "+--------------------------+" << std::endl
	<< "| Form:\t" << a->getName() << std::endl
	<< "| Grade to be signed:\t" << a->getGradeForSignature() << std::endl
	<< "| Grade to be executed:\t" << a->getGradeForExecution() << std::endl
	<< "| Signed: ";
	if (a->getSignedValue() == true)
		std::cout << "True";
	else
		std::cout << "False";
	std::cout << std::endl
	<< "+--------------------------+" <<std::endl;
	return (o);
}

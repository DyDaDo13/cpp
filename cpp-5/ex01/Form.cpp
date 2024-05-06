/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:19:40 by dylmarti          #+#    #+#             */
/*   Updated: 2024/05/06 15:04:43 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeForSignature(150), _gradeForExecution(150) {
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

Form::Form(std::string name): _name(name), _signed(false), _gradeForSignature(150), _gradeForExecution(150) {
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

Form::Form(size_t gradeForSignature, size_t gradeForExecution): _name("default"), _signed(false) {
	if (gradeForExecution > 150 || gradeForSignature > 150)
		throw Form::GradeTooLowException();
	else if (gradeForExecution < 1 || gradeForSignature < 1)
		throw Form::GradeTooHighException();
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

Form::Form(std::string name, size_t gradeForSignature, size_t gradeForExecution): _name(name), _signed(false) {
	if (gradeForExecution > 150 || gradeForSignature > 150)
		throw Form::GradeTooLowException();
	else if (gradeForExecution < 1 || gradeForSignature < 1)
		throw Form::GradeTooHighException();
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

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &cpy) {
	std::cout << "Form cpy constructor called" << std::endl;
	*this = cpy;
}

Form &Form::operator=(Form const &n) {
	std::cout << "Form assignement operator called" << std::endl;
	this->_name = n.getName();
	if (n.getSignedValue() == true)
		this->_signed = true;
	else
		this->_signed = false;
	this->_gradeForExecution = n.getGradeForExecution();
	this->_gradeForSignature = n.getGradeForSignature();
	return *this;
}

std::string	Form::getName(void) const {
	return this->_name;
}

size_t			Form::getGradeForSignature() const {
	return this->_gradeForSignature;
}

size_t			Form::getGradeForExecution() const {
	return this->_gradeForExecution;
}

bool		Form::getSignedValue() const {
	if (this->_signed == true)
		return true;
	return false;
}

void		Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeForSignature())
		throw Form::GradeTooLowException();
	else if (this->_signed == false){
		this->_signed = true;
		std::cout << this->getName() << " Signed by " << bureaucrat.getName() << std::endl;
	}
	else {
		std::cout << this->getName() << " cannot signed, already signed !" << std::endl;
	}
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "+--------------------------+" << std::endl
	<< "| Form:\t" << a->getName() << std::endl
	<< "| Grade to be signed:\t" << a->getGradeForSignature() << std::endl
	<< "| Grade to be executed:\t" << a->getGradeForSignature() << std::endl
	<< "| Signed: ";
	if (a->getSignedValue() == true)
		std::cout << "True";
	else
		std::cout << "False";
	std::cout << std::endl
	<< "+--------------------------+" <<std::endl;
	return (o);
}

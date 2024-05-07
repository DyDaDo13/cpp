/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:37:57 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/07 09:53:57 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called for " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy): AForm("RobotomyRequestFor", 25, 5), _target(cpy.getTarget()) {
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = cpy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &n) {
	std::cout << "PresidentialPardonForm assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executer) const {
	if (executer.getGrade() > this->getGradeForExecution())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSignedValue() == false)
		throw (AForm::FormNotSignedException());
	else {
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
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
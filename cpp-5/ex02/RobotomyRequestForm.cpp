/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:44:02 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/07 09:15:25 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called for " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy): AForm("RobotomyRequestFor", 72, 45), _target(cpy.getTarget()) {
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = cpy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &n) {
	std::cout << "RobotomyRequestForm assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executer) const {
	if (executer.getGrade() > this->getGradeForExecution())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSignedValue() == false)
		throw (AForm::FormNotSignedException());
	else {
		std::srand(std::time(0));
		if ((std::rand() % 2) == 0)
			std::cout << "BRRRRRRRRR!!! (drilling noises), " << this->getTarget() << " has been successfully robotomised" << std::endl;
		else
			std::cout << "robotomisation failed for " << this->getTarget() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
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
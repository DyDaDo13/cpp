/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:54:33 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/07 08:47:11 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called for " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy): AForm("ShrubberyCreationForm", 145, 137), _target(cpy.getTarget()) {
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = cpy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &n) {
	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executer) const {
	if (executer.getGrade() > this->getGradeForExecution())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSignedValue() == false)
		throw (AForm::FormNotSignedException());
	else {
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
		outfile << 
		"     V         ___            " << std::endl <<
		"  V  V      ###@#####         " << std::endl <<
		"   V      ########@####       " << std::endl <<
		"         #####@###@#####      " << std::endl <<
		"        #@##@####@#######     " << std::endl <<
		"        ####@##@@@##@####     " << std::endl <<
		"         ##@#@##@#######      " << std::endl <<
		"          ########@####  Q    " << std::endl <<
		"    Q       #########         " << std::endl <<
		"              |||||           " << std::endl <<
		"        Q     |||||    Q      " << std::endl <<
		"              |||||           " << std::endl <<
		"              |||||           " << std::endl <<
		"              ||@||           " << std::endl <<
		"     @       /|||||\\          " << std::endl <<
		"    \\|/     /|||||||\\            " << std::endl <<
		"11111|11111|||||||||||1111111111" << std::endl;
		outfile.close();
	}
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
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

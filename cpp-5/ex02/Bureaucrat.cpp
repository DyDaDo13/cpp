/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:00:11 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/06 15:38:44 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name): _name(name), _grade(150) {
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("default") {
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with the grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name) {
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with the grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const *cpy): _name(cpy->getName() + "_copy") {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called for " << this->getName() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &n) {
	std::cout << "Bureaucrat operator assignement called" << std::endl;
	this->_grade = n.getGrade();
	return *this;
}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

size_t	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void) {
	std::cout << "Bureaucrat incrementation called" << std::endl;
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void) {
	std::cout << "Bureaucrat decrementation called" << std::endl;
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}

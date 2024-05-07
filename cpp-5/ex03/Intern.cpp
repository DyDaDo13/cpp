/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:00:53 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/07 10:32:43 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &cpy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = cpy;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &n) {
	std::cout << "Intern assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}

static AForm	*makePresident(std::string const target) {
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(std::string const target) {
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(std::string const target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string const formName, std::string const target) {
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string FORM[] = { "PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm" };
	for (int i = 0; i < 3; i++) {
		if (formName == FORM[i]) {
			std::cout << "Intern creating a " << formName << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern cannot create a " << formName << " doesn't exist" << std::endl;
	return NULL;
}

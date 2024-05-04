/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:18:18 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/04 22:44:47 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat *a = new Bureaucrat();
	std::cout << a;
	try {
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &error) {
		std::cerr << "Incrementing the grade of " << a->getName() << " failed: " << error.what() << std::endl;
	}
	std::cout << a;
	try {
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &error) {
		std::cerr << "Decrementing the grade of " << a->getName() << " failed: " << error.what() << std::endl;
	}
	std::cout << a;
	try {
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &error) {
		std::cerr << "Decrementing the grade of " << a->getName() << " failed: " << error.what() << std::endl;
	}
	std::cout << a;
	std::cout << std::endl;
	delete a;
	
	std::cout << std::endl << "-----------------------------------------------------------------------------------------------" << std::endl;
	
	Bureaucrat *b = new Bureaucrat("bob", 1);
	std::cout << b;
	try {
		b->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &error) {
		std::cerr << "Incrementing the grade of " << b->getName() << " failed: " << error.what() << std::endl;
	}
	std::cout << b;
	try {
		b->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &error) {
		std::cerr << "Decrementing the grade of " << b->getName() << " failed: " << error.what() << std::endl;
	}
	std::cout << b;
	try {
		b->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &error) {
		std::cerr << "Decrementing the grade of " << b->getName() << " failed: " << error.what() << std::endl;
	}
	std::cout << b;
	std::cout << std::endl;
	delete b;
	
	std::cout << std::endl << "-----------------------------------------------------------------------------------------------" << std::endl;
	
	std::cout << std::endl;
	Bureaucrat *c = NULL;
	try {
		c = new Bureaucrat(160);
	}
	catch(Bureaucrat::GradeTooLowException &error) {
		std::cerr << "Constructing default failed: " << error.what() << std::endl;
	}
	if (c != NULL)
		delete c;
	std::cout << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:18:18 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/06 11:31:43 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	
	Form *test = new Form();
	delete test;
	
	Form *test1 = new Form(12, 13);
	delete test1;
	
	Form *test2;
	try {	
		test2 = new Form("jhon", 160, 151);
	}
	catch (Form::GradeTooLowException &error)
	{
		std::cout << "error while creating Form invalid agruments" << std::endl;
	}
	if (test2 != NULL)
		delete test2;

	std::cout << std::endl;
	return 0;
}

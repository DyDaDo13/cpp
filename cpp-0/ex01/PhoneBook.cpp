/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:47 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/26 21:30:58 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook() {
	this->newContactIndex = 0;
	this->contactNumbers = 0;
	for (int i = 0; i < this->C_MAX; i++) {
		this->contacts[i] = new Contact;
	}
}

PhoneBook::~PhoneBook() {
	for (int i = 0; i < this->C_MAX; i++) {
		delete this->contacts[i];
	}
}

void	PhoneBook::add() {
	if (this->newContactIndex >= this->C_MAX ) this->newContactIndex = 0;

	std::string	line;
	Contact	*contact = new Contact();
	if (contact->setInfo(this->newContactIndex + 1) == 0) {
		delete this->contacts[this->newContactIndex];
		this->contacts[this->newContactIndex] = contact;
		std::cout << "\nNew Contact Added Succesfully !\n";
		this->newContactIndex++;

		if (this->contactNumbers < 8) this->contactNumbers++;
	} else
		delete contact;
	std::cout << std::endl;
	return ;
}

void	PhoneBook::search() {
	std::string	line;
	if (this->contactNumbers == 0) {
		std::cout << "\nError: no contacts\n" << std::endl;
		return ;
	}
	std::cout << "\n"
	<< "+-------------------------------------------+\n"
	<< "|     index| FirstName|  LastName|  Nickname|\n"
	<< "+-------------------------------------------+\n"
	<< "+-------------------------------------------+\n";
	for (int i = 0; i < this->contactNumbers; i++)
		this->contacts[i]->print_contacts();
	std::cout << "+-------------------------------------------+\n";
	std::cout << std::endl;
	while (std::cout << "INDEX > ", std::getline(std::cin, line)) {
		if (line >= "1" && line <= "9" && line[0] - 1 - '0' == this->contactNumbers - 1) {	
			this->contacts[line[0] - 1 - '0']->printInfo();
		}
		else if (line == "EXIT") {
			std::cout << "exiting..." << std::endl;
			break ;
		} else if (std::cin.eof())
			break ;
		else
			std::cout << "Invalid Index: Out of range" << std::endl;
		std::cin.clear();
	}
	std::cin.clear();
}

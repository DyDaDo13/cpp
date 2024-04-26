/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:56 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/26 19:03:17 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

bool	check_isalpha(std::string &str) {
	for (std::string::const_iterator c = str.begin(); c != str.end(); c++) {
		if (std::isalpha(*c)) return true;
	}
	return (false);
}

bool	check_isalnum(std::string &str) {
	for (std::string::const_iterator c = str.begin(); c != str.end(); c++) {
		if (std::isalnum(*c)) return true;
	}
	return (false);
}

int	Contact::setInfo(int index) {
	int	i;
	this->index = index;
	i = 0;
	
	do {
	std::cout << "Enter firstName Here > ";
	std::getline(std::cin, this->stringInfo[i]);
	
	if (std::cin.eof()) {std::cin.clear(); return 1;}
	} while (this->stringInfo[i].empty() || !check_isalpha(this->stringInfo[i]));
	i++;
	do {
	std::cout << "Enter lastName Here > ";
	std::getline(std::cin, this->stringInfo[i]);
	
	if (std::cin.eof()) {std::cin.clear(); return 1;}
	} while (this->stringInfo[i].empty() || !check_isalpha(this->stringInfo[i]));
	i++;
	do {
	std::cout << "Enter nickName Here > ";
	std::getline(std::cin, this->stringInfo[i]);
	
	if (std::cin.eof()) {std::cin.clear(); return 1;}
	} while (this->stringInfo[i].empty());
	i++;
	do {
	std::cout << "Enter number Here > ";
	std::getline(std::cin, this->stringInfo[i]);
	
	if (std::cin.eof()) {std::cin.clear(); return 1;}
	} while (this->stringInfo[i].empty() || !check_isalnum(this->stringInfo[i]));
	i++; 
	do {
	std::cout << "Enter DarkSecret Here > ";
	std::getline(std::cin, this->stringInfo[i]);
	
	if (std::cin.eof()) {std::cin.clear(); return 1;}
	} while (this->stringInfo[i].empty());

	if (this->stringInfo[0].length() == 0) {
		std::cout << "\nerror: name is requiered\n";
		return 1;
	}
	return 0;
}

void	Contact::print_contacts() {
	// check la len de tout les arguments 
	// met un point a la fin et verifier que la len de la case fasse bien 10 char
	// rechercher si il nexiste pas une fonction standanrd pour ecrire directement a droite
	std::cout << "|" << std::setw(10) << std::right << this->index << "|";
	std::cout << std::setw(10) << std::right << this->stringInfo[0] << "|";
	std::cout << std::setw(10) << std::right << this->stringInfo[1] << "|";
	std::cout << std::setw(10) << std::right << this->stringInfo[2] << "|"
	<< std::endl;
}

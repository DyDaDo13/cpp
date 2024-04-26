/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:56 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/26 21:39:51 by dydado13         ###   ########.fr       */
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
		if (!std::isdigit(*c)) {
			return false;
		}
	}
	return true;
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
	std::cout << "|" << std::setw(10) << std::right << this->index << "|";
	for (int i = 0; i < 3; i++) {
		if (this->stringInfo[i].length() > 10)
			std::cout << this->stringInfo[i].substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << std::right << this->stringInfo[i] << "|";
	}
	std::cout << std::endl;
}

void	Contact::printInfo() {
	std::cout << std::endl;
	std::cout << "NAME : " << this->stringInfo[firstName] << std::endl;
	std::cout << "LAST NAME : " << this->stringInfo[lastName] << std::endl;
	std::cout << "NICKNAME : " << this->stringInfo[nickName] << std::endl;
	std::cout << "PHONE : " << this->stringInfo[phone] << std::endl;
	std::cout << "DARK SECRET : " << this->stringInfo[DarkSecret] << std::endl;
	std::cout << std::endl;
}

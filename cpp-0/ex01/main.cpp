/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:50 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 10:30:00 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>

int main() {
	std::string	line;
	PhoneBook *phoneBook = new PhoneBook();
	
	std::cout << "Welcome to the PhoneBook !" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	while (std::cout << "$> ", std::getline(std::cin, line)) {
		if (line == "ADD")
			phoneBook->add();
		else if (line == "SEARCH")
			phoneBook->search();
		else if (line == "EXIT") {
			std::cout << "exiting..." << std::endl;
			break ;
		} else if (std::cin.eof())
			break ;
		std::cin.clear();
	}
	std::cin.clear();
	delete phoneBook;
	return (0);
}

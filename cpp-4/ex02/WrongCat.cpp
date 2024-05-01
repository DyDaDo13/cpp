/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:14:40 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:15:54 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type) {
	std::cout << "WrongCat Constructor called for " << type << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy): WrongAnimal(cpy) {
	*this = cpy;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &n) {
	this->_type = n._type;
	std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "The wrong cat do 'MEOW'" << std::endl;
}

std::string WrongCat::getType() const {
	return this->_type;
}
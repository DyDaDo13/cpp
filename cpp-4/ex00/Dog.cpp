/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:26:40 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:04:08 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type): Animal(type) {
	std::cout << "Dog Constructor called for " << type << std::endl;
}

Dog::Dog(Dog const &cpy): Animal(cpy) {
	*this = cpy;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &n) {
	this->_type = n._type;
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "the dog do 'WOUAF'" << std::endl;
}

std::string Dog::getType() const {
	return this->_type;
}

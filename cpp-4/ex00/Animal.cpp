/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:05:27 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:32:12 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("default") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::Animal(Animal const &cpy) {
	this->_type = cpy._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &n) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->_type = n._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}

void Animal::makeSound() const {
	std::cout << "animal do a generic sound of animal ..." << std::endl;
}

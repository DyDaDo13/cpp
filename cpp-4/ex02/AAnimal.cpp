/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:05:27 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/01 16:28:37 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("default") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type) {
	std::cout << "AAnimal constructor called for " << type << std::endl;
}

AAnimal::AAnimal(AAnimal const &cpy) {
	this->_type = cpy._type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &n) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	this->_type = n._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return (this->_type);
}

void AAnimal::makeSound() const {
}

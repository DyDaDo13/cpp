/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:16:42 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 20:39:44 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal() {
	this->_brain = new Brain;
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type): Animal(type) {
	this->_brain = new Brain;
	std::cout << "Cat Constructor called for " << type << std::endl;
}

Cat::Cat(Cat const &cpy): Animal(cpy) {
	*this = cpy;
	this->_brain = new Brain(*(cpy.getBrain()));
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &n) {
	this->_type = n._type;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(n.getBrain()));
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "The cat do 'MIAOU'" << std::endl;
}

std::string Cat::getType() const {
	return this->_type;
}

Brain *Cat::getBrain() const {
	return (this->_brain);
}


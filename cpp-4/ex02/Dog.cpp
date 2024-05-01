/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:26:40 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/01 16:28:05 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): AAnimal() {
	this->_brain = new Brain;
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type): AAnimal(type) {
	this->_brain = new Brain;
	std::cout << "Dog Constructor called for " << type << std::endl;
}

Dog::Dog(Dog const &cpy): AAnimal(cpy) {
	
	*this = cpy;
	this->_brain = new Brain(*(cpy.getBrain()));
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &n) {
	this->_type = n._type;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(n.getBrain()));
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "the dog do 'WOUAF'" << std::endl;
}

std::string Dog::getType() const {
	return this->_type;
}

Brain *Dog::getBrain() const {
	return (this->_brain);
}

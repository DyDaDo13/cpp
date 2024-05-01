/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:47:35 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 20:41:10 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Brain ideas";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &cpy) {
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = cpy._ideas[i] + " stolen";
	std::cout << "Brain copy constructor called and have stolent ideas" << std::endl;
}

Brain &Brain::operator=(Brain const &n) {
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = n._ideas[i] + " stolen";
	return (*this);
}

Brain::~Brain() {
	delete [] (this->_ideas);
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeas() const {
	return *this->_ideas;
}


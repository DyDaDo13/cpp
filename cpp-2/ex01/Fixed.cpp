/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:37:22 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/28 13:49:22 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits(src.getRawBits());
	*this = src;
}

Fixed::Fixed(int const n): _value(n << _bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float n) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(n * (1 << this->_bits)));
}

Fixed& Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void    Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat() const {
	return ((float)this->getRawBits() / (1 << this->_bits));
}

int	Fixed::toInt(void) const {
	return this->_value >> _bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}

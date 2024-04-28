/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:37:22 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/28 14:27:52 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	//std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits(src.getRawBits());
	*this = src;
}

Fixed::Fixed(int const n): _value(n << _bits) {
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float n) {
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(n * (1 << this->_bits)));
}

Fixed& Fixed::operator=(Fixed const &src) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator<(Fixed const &src) const { return (this->getRawBits() < src.getRawBits()); }
bool Fixed::operator>(Fixed const &src) const { return (this->getRawBits() > src.getRawBits()); }
bool Fixed::operator>=(Fixed const &src) const { return (this->getRawBits() >= src.getRawBits()); }
bool Fixed::operator<=(Fixed const &src) const { return (this->getRawBits() <= src.getRawBits()); }
bool Fixed::operator!=(Fixed const &src) const { return (this->getRawBits() != src.getRawBits()); }
bool Fixed::operator==(Fixed const &src) const { return (this->getRawBits() == src.getRawBits()); }

Fixed Fixed::operator+(Fixed const &src) const { return (Fixed(this->toFloat() + src.toFloat())); }
Fixed Fixed::operator-(Fixed const &src) const { return (Fixed(this->toFloat() - src.toFloat())); }
Fixed Fixed::operator*(Fixed const &src) const { return (Fixed(this->toFloat() * src.toFloat())); }
Fixed Fixed::operator/(Fixed const &src) const { return (Fixed(this->toFloat() / src.toFloat())); }

Fixed &Fixed::operator++(void) {
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--(void) {
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}

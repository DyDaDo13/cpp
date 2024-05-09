/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:08:23 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 14:40:41 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	// std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &cpy) {
	// std::cout << "Serializer copy constructor called" << std::endl;
	*this = cpy;
}

Serializer &Serializer::operator=(Serializer const &n) {
	// std::cout << "Serializer assignement operator called" << std::endl;
	if (this == &n)
		return (*this);
	return (*this);
}

Serializer::~Serializer() {
	// std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

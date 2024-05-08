/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:19:47 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/08 16:22:22 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	// std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy) {
	// std::cout << "ScalarConverter copy contructor called" << std::endl;
	*this = cpy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &n) {
	// std::cout << "ScalarConverter assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	// std::cout << "Scalarconverter destructor called" << std::endl;
}

std::string	ScalarConverter::getType(std::string literal) const {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return "double";
	else if (literal.length() > 3 && literal.at(literal.length() - 1) == 'f')
		return "float";
	else if (literal.length() > 2 && literal.find(".") != std::string::npos)
		return "double";
	else if (literal.length() == 1) {
		char c = literal.at(0);
		if (c >= '0' && c <= '9')
			return "int";
		else if (c >= 32 && c <= 126)
			return "char";
		else
			return "invalid";
	}
	else
		return "int";
}

void	ScalarConverter::print(int n) const {
	if (n < 32 || n > 126)
		std::cout << "char non displayable" << std::endl;
	else if (n > 256 || n < 0)
		std::cout << "char impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void	ScalarConverter::print(char c) const {
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::print(double d) const {
	if (d < 32 || d > 126)
		std::cout << "char non displayable" << std::endl;
	else if (d > 256 || d < 0 || d != d)
		std::cout << "char impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (d > 2148473647 || d < -2147483648 || d != d) {
		std::cout << "int impossible" << std::endl;
	}
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > __FLT_MAX__ || d < __FLT_MIN__) {
		std::cout << "float impossible" << std::endl;
	}
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
}

void	ScalarConverter::print(float f) const {
	if (f < 32 || f > 126)
		std::cout << "char non displayable" << std::endl;
	else if (f > 256 || f < 0 || f != f)
		std::cout << "char impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (f > 2148473647 || f < -2147483648 || f != f) {
		std::cout << "int impossible" << std::endl;
	}
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

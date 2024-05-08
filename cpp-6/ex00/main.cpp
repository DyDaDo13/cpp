/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:51:39 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/08 16:15:09 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2)
		return (std::cout << "Error: too many or less arguments" << std::endl, 1);
	else if (av[1][0] == '\0')
		return (std::cout << "Error: invalid argument" << std::endl, 2);

	ScalarConverter converter;
	std::string literal = static_cast<std::string>(av[1]);
	std::string	type = converter.getType(literal);

	if (type == "int") {
		int num = std::atoi(literal.c_str());
		converter.print(num);
	}
	else if (type == "char") {
		char c = literal.at(0);
		converter.print(c);
	}
	else if (type == "double") {
		double d = static_cast<double>(std::atof(literal.c_str()));
		converter.print(d);
	}
	else if (type == "float") {
		float f = std::atof(literal.c_str());
		converter.print(f);
	}
	else if (type == "invalid")
		std::cout << "invalid character input" << std::endl;
	return 0;
}

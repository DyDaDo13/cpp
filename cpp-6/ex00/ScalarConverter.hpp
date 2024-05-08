/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:15:12 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/08 16:07:38 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP_
# define SCALARCONVERTER_HPP_

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits.h>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &cpy);
		ScalarConverter &operator=(ScalarConverter const &n);
		~ScalarConverter();

		std::string getType(std::string literal) const;
		void	print(char c) const;
		void	print(int n) const;
		void	print(float f) const;
		void	print(double d) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:49:29 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/22 16:09:54 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN {
	public:
		RPN() {}
		RPN(std::string const &input);
		RPN(RPN const &cpy);
		RPN &operator=(RPN const &n);
		~RPN() {};

		int	doMath(void);
	private:
		std::string _input;
		int	_a, _b, _r;

	class Error : public std::exception {
		virtual const char *what() const throw() {
			return "Error";
		}
	};
};

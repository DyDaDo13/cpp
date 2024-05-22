/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:50:11 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/22 16:18:07 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &input): _input(input) {}
RPN::RPN(RPN const &cpy) {
	*this = cpy;
}

RPN &RPN::operator=(RPN const &n) {
	this->_input = n._input;
	this->_a = n._a;
	this->_b = n._b;
	this->_r = n._r;
	return *this;
}

int checkInvalidCharacter(std::string str) {
	for (size_t i = 0; i < str.length(); i++)
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			return 1;
	return 0;
}

int RPN::doMath(void) {
	std::stack<int> stack;
	std::stringstream ss(_input);
	int result = 0;
	
	for (std::string token; ss >> token;) {
		if (checkInvalidCharacter(token)) {
			throw Error();
		}
		stack.push(atoi(token.c_str()));
		if (token == "+" || token == "-" || token == "/" || token == "*") {
			if (stack.size() < 3)
				throw Error();
			stack.pop();
			_a = stack.top();
			stack.pop();
			_b = stack.top();
			stack.pop();
			if (token == "+")
				_r = _b + _a;
			else if (token == "-")
				_r = _b - _a;
			else if (token == "*")
				_r = _b * _a;
			else if (token == "/")
				_r = _b / _a;
			stack.push(_r);
		}
	}
	if (stack.size() > 1)
		throw Error();
	result = _r;
	return result;
}




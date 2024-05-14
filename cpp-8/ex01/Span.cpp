/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:19:27 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/14 14:56:45 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {
	// std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const &cpy) {
	// std::cout << "Span copy constructor called" << std::endl;
	*this = cpy;
}

Span &Span::operator=(Span const &n) {
	// std::cout << "Span assignement operator called" << std::endl;
	if (this == &n)
		return *this;
	return *this;
}

Span::~Span() {
	// std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_maxSize)
		throw Span::SpanIsFull();
	this->_numbers.push_back(number);
}



int Span::shortestSpan() const {
	if (this->_numbers.size() < 2)
		throw Span::SpanIsTooTiny();
	std::vector<int> sorted(this->_numbers);
	std::sort(sorted.begin(), sorted.end());
	int shortest = sorted[1] - sorted[0];
	for (std::vector<int>::size_type i = 2; i != sorted.size(); i++) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const {
	if (this->_numbers.size() < 2)
		throw Span::SpanIsTooTiny();
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	return max - min;
}

void Span::printSpan() const {
	for (std::vector<int>::size_type i = 0; i != this->_numbers.size(); i++) {
		std::cout << "[" << this->_numbers[i] << "]";
	}
	std::cout << std::endl;
}

const char *Span::SpanIsFull::what(void) const throw() {
	return ("Span is full");
};

const char *Span::SpanIsTooTiny::what(void) const throw() {
	return ("Span is too tiny");
};



/*

To implement the shortestSpan and longestSpan functions, you need to iterate over the numbers stored in _numbers and calculate the differences between them.

For shortestSpan, you want to find the smallest difference between any two numbers. For longestSpan, you want to find the largest difference.

Before you start calculating, you should check if there are less than two numbers in _numbers. If there are, throw an exception, because you can't calculate a span with less than two numbers.

Here's a basic plan for each function:

shortestSpan:

If the size of _numbers is less than 2, throw an exception.
Sort _numbers.
Initialize shortest to the difference between the first two numbers.
Iterate over _numbers from the second number to the end. For each number, calculate the difference between it and the previous number. If the difference is less than shortest, update shortest.
Return shortest.
longestSpan:

If the size of _numbers is less than 2, throw an exception.
Return the difference between the maximum and minimum elements in _numbers.



int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers");
    }
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (std::vector<int>::size_type i = 2; i != sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers");
    }
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}
*/
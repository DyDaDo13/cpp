/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:19:41 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/14 14:48:02 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

class Span {
	public:
		Span(unsigned int N);
		Span(Span const &cpy);
		Span &operator=(Span const &n);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		void printSpan() const;
		
		class SpanIsFull : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class SpanIsTooTiny : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

#endif

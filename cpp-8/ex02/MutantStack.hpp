/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:03:48 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/14 15:59:37 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

#ifndef MUTANTSTACK_HPP_
# define MUTANTSTACK_HPP_


template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {};
		MutantStack(MutantStack const &cpy) : std::stack<T>(cpy) {}
		MutantStack &operator=(MutantStack const &n) {
			if (this == &n)
				return *this;
			return *this;
		}
		~MutantStack() {};
		
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}
};

#endif

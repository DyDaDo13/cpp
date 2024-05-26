/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:19 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/26 18:33:10 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &cpy);
		PmergeMe &operator=(PmergeMe const &n);
		~PmergeMe(void);
		
		void sortVec(int ac, char **av);
		void sortList(int ac, char **av);
		
		class InvalidElementException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
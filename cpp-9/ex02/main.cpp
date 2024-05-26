/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:32 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/26 19:02:47 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int ft_stou(const std::string& str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

int main(int ac, char **av) {
	if (ac == 1)
		return (std::cout << "Error: Invalid input" << std::endl, 1);
	PmergeMe pme;
	
	try {
		for (int i = 1; i < ac; i++) {
			if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
				throw PmergeMe::InvalidElementException();
		}
		std::vector<unsigned int> temp;
		for (int i = 1; i < ac; i++)
			temp.push_back(ft_stou(av[i]));
		
		std::vector<unsigned int>::iterator itr;
		std::vector<unsigned int>::iterator itr2;
		for (itr = temp.begin(); itr != temp.end(); itr++)
			for (itr2 = itr + 1; itr2 != temp.end(); itr2++)
				if (*itr2 == *itr)
					throw PmergeMe::InvalidElementException();
	} catch (std::exception &error) {
		return (std::cerr << error.what() << std::endl, 1);
	}
	
	pme.sortVec(ac, av);
	std::cout << std::endl;
	pme.sortList(ac, av);

	return 0;
}
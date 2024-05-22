/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:35:57 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/22 16:35:58 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main() {
	
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	int target1 = 3;
	try {
		std::vector<int>::iterator result1 = easyfind(numbers, target1);
		std::cout << "Element " << target1 << " found at index " << std::distance(numbers.begin(), result1) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	int target2 = 6;
	try {
		std::vector<int>::iterator result2 = easyfind(numbers, target2);
		std::cout << "Element " << target2 << " found at index " << std::distance(numbers.begin(), result2) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

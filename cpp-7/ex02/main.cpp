/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:27:57 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 17:05:44 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VALUE 750
int main(int, char**) {
    Array<int> numbers(MAX_VALUE);
    int* mirror = new int[MAX_VALUE];
	
    srand(time(NULL));
	
    for (int i = 0; i < MAX_VALUE; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	Array<int> tmp;
	try {
		for (int i = 0; i < MAX_VALUE + 1; i++)
			std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\t';
		std::cerr << "You tried to access past the last element of the array" << std::endl;
	}
	tmp = numbers;
	Array<int> test(tmp);

	try {
		for (int i = 0; i < MAX_VALUE + 1; i++) {
			if (tmp[i] != test[i])
				return (std::cerr << "didn't save the same value!!" << std::endl, 1);
			// std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
			// std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\t';
		std::cerr << "You tried to access past the last element of the array" << std::endl;
	}

	std::cout << std::endl << "test[1]:\t" << test[1] << std::endl;
	std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

	test[1] = 123456789;

	std::cout << "test[1]:\t" << test[1] << std::endl;
	std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

    for (int i = 0; i < MAX_VALUE; i++)
        if (mirror[i] != numbers[i])
            return (std::cerr << "didn't save the same value!!" << std::endl, 1);
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "index was -2" << std::endl;
    }
    try {
        numbers[MAX_VALUE] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "tried to access past the last element of the array" << std::endl;
    }

    delete [] mirror;
    return 0;
}
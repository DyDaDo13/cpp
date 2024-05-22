/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:37 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/22 16:12:45 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
	if (ac != 2)
		return (std::cout << "Error: Invalid input" << std::endl, 1);
	
	int result;
	RPN numbers(av[1]);
	try {
		result = numbers.doMath();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	std::cout << result << std::endl;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:15:00 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 17:09:32 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	harlCheckNumber(char *av) {
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {
		if (levels[i] == av)
			return i;
	}
	return -1;
}

void	harlSwitch(char *av, Harl & H) {
	switch (harlCheckNumber(av)) {
		case 0:
			H.complain("DEBUG");
		case 1:
			H.complain("INFO");
		case 2:
			H.complain("WARNING");
		case 3:
			H.complain("ERROR");
			break ;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int ac, char **av) {
	Harl H;
	if (ac != 2)
		return (std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
	else
		harlSwitch(av[1], H);
	return (0);
}
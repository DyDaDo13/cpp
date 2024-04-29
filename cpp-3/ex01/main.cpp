/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:04:07 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 12:23:14 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
	ScavTrap Scav("jeb");
	ClapTrap Clap("bob");

	Clap.attack("kevin");
	Scav.attack("jeb");
	Scav.guardGate();
	Scav.guardGate();
	return 0;
}
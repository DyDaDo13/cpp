/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:09:35 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 12:16:15 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name) {
	return (new Zombie(name));
}

void	randomChump(std::string name) {
	Zombie z = Zombie(name);
	z.announce();
}

int main() {
	Zombie *z = newZombie("jean");
	z->announce();
	randomChump("bob");
	delete z;
	return (0);
}
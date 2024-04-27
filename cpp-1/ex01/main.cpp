/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:09:35 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 13:10:32 by dydado13         ###   ########.fr       */
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

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}

int main() {
	int size = 10;
	
	Zombie *horde = zombieHorde(size, "zom");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde; // free un tableau de tableau
	return (0);
}
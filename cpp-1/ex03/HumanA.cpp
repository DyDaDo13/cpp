/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:17:34 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 14:49:36 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon): _name(name), _weapon(Weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) {
	std::cout << "HumanA: " << this->_name << " attack with ";
	std::cout << _weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &Weapon) {
	this->_weapon = Weapon;
}

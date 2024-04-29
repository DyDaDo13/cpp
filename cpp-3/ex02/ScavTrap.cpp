/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:28:37 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 13:14:30 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isInGuardMode = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isInGuardMode = false;
	std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &n): ClapTrap(n) {
	this->_isInGuardMode = n._isInGuardMode;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &n) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->_attackDamage = n._attackDamage;
	this->_energyPoints = n._energyPoints;
	this->_hitPoints = n._hitPoints;
	this->_name = n._name;
	return (*this);
}

void	ScavTrap::attack(std::string const &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ScavTrap attacking " << target << " causing " << this->_attackDamage << " points of damages!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap out of energy!" << std::endl;
	else
		std::cout << "ScavTrap don't have enough hit points" << std::endl;
}

void	ScavTrap::guardGate() {
	if (this->_isInGuardMode == false) {
		std::cout << "ScavTrap is now guarding the gate!" << std::endl;
		this->_isInGuardMode = true;
	}
	else
		std::cout << "ScavTrap already guarding the gate!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:54:01 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 13:29:01 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &n) {
	this->_attackDamage = n._attackDamage;
	this->_hitPoints = n._hitPoints;
	this->_energyPoints = n._energyPoints;
	this->_name = n._name;
	std::cout << "FragTrap assignation operator called" << std::endl;
	return *this;
}

FragTrap::FragTrap(FragTrap const &cpy): ClapTrap(cpy) {
	std::cout << "FragTrap copy contructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(std::string const &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "FragTrap attacking " << target << " causing " << this->_attackDamage << " points of damages!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "FragTrap out of energy!" << std::endl;
	else
		std::cout << "FragTrap don't have enough hit points" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "HEY GUYS LET'S DO A HIGHFIVE !!! \n\t 'CLAP!'\n" << std::endl;
}

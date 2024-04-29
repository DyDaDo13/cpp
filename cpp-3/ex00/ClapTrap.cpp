/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:06:32 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 13:27:09 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _energyPoints(10), _attackDamage(0), _hitPoints(10) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _energyPoints(10), _attackDamage(0), _hitPoints(10) {
	std::cout << "ClapTrap constructor called for the name " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &n) {
	*this = n;
	std::cout << "ClapTrap copy constructor called";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &s) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = s._name;
	this->_attackDamage = s._attackDamage;
	this->_energyPoints = s._energyPoints;
	this->_hitPoints = s._hitPoints;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap attacking " << target << " causing " << this->_attackDamage << " points of damages!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap out of energy!" << std::endl;
	else
		std::cout << "ClapTrap don't have enough hit points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= amount) {
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	_hitPoints -= 1;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << "hit points!" << std::endl;
	_energyPoints -= 1;
	_hitPoints += amount;
}

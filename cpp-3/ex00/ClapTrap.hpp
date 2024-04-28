/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:00:26 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/28 20:00:26 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <iostream>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &c);
		ClapTrap &operator=(ClapTrap const &s);
		~ClapTrap();
		
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	_name;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		unsigned int	_hitPoints;
};

#endif

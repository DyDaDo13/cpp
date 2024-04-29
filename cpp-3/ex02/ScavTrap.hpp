/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:07:08 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 12:06:47 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &n);
		ScavTrap &operator=(ScavTrap const &n);
		~ScavTrap();

		void attack(std::string const &target);
		void guardGate(void);

	private:
		bool _isInGuardMode;
};

#endif

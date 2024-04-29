/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:53:39 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 13:00:02 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &cpy);
		FragTrap &operator=(FragTrap const &n);
		~FragTrap();

		void attack(std::string const &target);
		void highFivesGuys(void);
		
	private:
};

#endif
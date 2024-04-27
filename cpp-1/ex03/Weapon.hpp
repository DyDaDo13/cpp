/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:48:34 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 14:36:07 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
# define WEAPON_HPP_

#include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType(void);
		void	setType(std::string type);
	private:
		std::string	_type;
};

#endif
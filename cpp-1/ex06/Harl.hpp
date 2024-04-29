/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:15:04 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/29 14:46:04 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
# define HARL_HPP_

#include <iostream>

class Harl {
	public:
		Harl();
		~Harl();
		void	complain(std::string message);
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
};

#endif

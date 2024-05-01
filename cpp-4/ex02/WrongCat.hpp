/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:11:50 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:26:41 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const &cpy);
		WrongCat &operator=(WrongCat const &n);
		~WrongCat();
		std::string getType() const;
		void makeSound() const;
	private:
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:08:22 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:22:24 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &cpy);
		WrongAnimal &operator=(WrongAnimal const &n);
		~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string _type;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:01:55 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:28:02 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &cpy);
		Animal &operator=(Animal const &n);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string _type;
};

#endif
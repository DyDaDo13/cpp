/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:27:24 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/01 16:26:56 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
# define DOG_HPP_

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &cpy);
		Dog &operator=(Dog const &n);
		~Dog();

		std::string getType() const;
		Brain *getBrain() const;
		void makeSound() const;
	private:
		Brain* _brain;
};

#endif
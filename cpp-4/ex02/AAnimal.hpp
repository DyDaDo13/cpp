/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:01:55 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/01 16:32:48 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP_
# define AANIMAL_HPP_

#include <iostream>

class AAnimal {
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const &cpy);
		AAnimal &operator=(AAnimal const &n);
		virtual ~AAnimal();
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
	protected:
		std::string _type;
};

#endif
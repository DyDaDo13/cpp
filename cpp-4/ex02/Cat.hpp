/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:14:53 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 13:02:14 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
# define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const &cpy);
		Cat &operator=(Cat const &n);
		~Cat();

		std::string getType() const;
		void deepCopyProof(Cat const &other_cat) const;
		Brain *getBrain() const;
		void makeSound() const;
	private:
		Brain* _brain;
};

#endif
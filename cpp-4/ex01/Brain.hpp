/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:47:32 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 13:07:38 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
# define BRAIN_HPP_

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const &cpy);
		Brain &operator=(Brain const &n);
		~Brain();
		std::string getIdeas() const;
	private:
		std::string *_ideas;
};


#endif
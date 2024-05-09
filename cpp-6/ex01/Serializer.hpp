/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:03:05 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 14:37:46 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct		Data {
	std::string	name;
	size_t		age;
	Data		*next;
}					Data;

class Serializer {
	public:
		Serializer();
		Serializer(Serializer const &cpy);
		Serializer &operator=(Serializer const &n);
		~Serializer();

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
	private:
};

#endif

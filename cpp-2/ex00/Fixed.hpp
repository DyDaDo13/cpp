/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:12:39 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/28 12:43:47 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
# define FIXED_HPP_

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed& operator=(Fixed const &src);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int _value;
	static const int _bits = 8;
};

#endif

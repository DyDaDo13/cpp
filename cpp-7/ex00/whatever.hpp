/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:23:14 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 15:27:01 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

const T &min(const T &x, const T &y) {
	if (x <= y)
		return x;
	return y;
}

template <typename A>
const A &max(const A &x, const A &y) {
	if (x >= y)
		return x;
	return y;
}

template <typename G>
void	swap(G &x, G &y) {
	G tmp = x;
	x = y;
	y = tmp;
}

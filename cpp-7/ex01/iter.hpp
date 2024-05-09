/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:36:49 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 15:40:41 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
template <typename T>

void iter(T *a, int size, void (*func)(T &)) {
	if (a == NULL || func == NULL)
		return ;
	for (int i = 0; i < size; i++)
		func(a[i]);
}

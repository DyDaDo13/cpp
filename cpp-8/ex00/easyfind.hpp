/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:17:07 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/12 14:37:55 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

class NotFoundException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Element not found in container";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

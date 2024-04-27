/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:53 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/27 10:30:51 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
# define CONTACT_HPP_

#include <iostream>

class Contact {
	public:
		Contact();
		~Contact();
		int	setInfo(int index);
		void	print_contacts();
		void	printInfo();
	private:
		static const int	C_CNT = 5;		
		enum content {
			firstName = 0,
			lastName,
			nickName,
			phone,
			DarkSecret
		};
		int index;
		std::string	stringInfo[C_CNT];
};

#endif
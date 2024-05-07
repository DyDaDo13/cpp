/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:32:35 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/06 21:16:01 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &n);
		~ShrubberyCreationForm();
		
		std::string	getTarget() const;
		void	execute(Bureaucrat const &executer) const;
	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif

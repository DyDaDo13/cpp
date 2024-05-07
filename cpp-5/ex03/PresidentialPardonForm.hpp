/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:38:17 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/07 09:52:26 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &cpy);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &n);
		~PresidentialPardonForm();
		
		std::string	getTarget() const;
		void	execute(Bureaucrat const &executer) const;
	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif
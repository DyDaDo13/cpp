/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:44:18 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/07 08:45:05 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &cpy);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &n);
		~RobotomyRequestForm();
		
		std::string	getTarget() const;
		void	execute(Bureaucrat const &executer) const;
	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:09:34 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/06 14:54:43 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_


#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const name);
		Bureaucrat(int grade);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const *cpy);
		Bureaucrat &operator=(Bureaucrat const &n);
		~Bureaucrat();

		std::string	getName(void) const;
		size_t		getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form &form);

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	
	private:
		void		setGrade(int grade);
		std::string const	_name;
		size_t	_grade;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:19:59 by dylmarti          #+#    #+#             */
/*   Updated: 2024/05/06 20:40:56 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
# define AFORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(AForm const &cpy);
		AForm &operator=(AForm const &n);
		virtual ~AForm();

		std::string	getName(void) const;
		size_t			getGradeForSignature() const;
		size_t			getGradeForExecution() const;
		bool		getSignedValue() const;
		void		beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor)const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		
		class FormNotSignedException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

	protected:
		AForm();
		AForm(std::string name);
		AForm(size_t gradeForSignature, size_t gradeForExecution);
		AForm(std::string name, size_t gradeForSignature, size_t gradeForExecution);

		std::string	_name;
		bool			_signed;
		size_t			_gradeForSignature;
		size_t			_gradeForExecution;
};

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:19:59 by dylmarti          #+#    #+#             */
/*   Updated: 2024/05/06 11:27:06 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
# define FORM_HPP_

#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(std::string name);
		Form(size_t gradeForSignature, size_t gradeForExecution);
		Form(std::string name, size_t gradeForSignature, size_t gradeForExecution);
		Form(Form const &cpy);
		Form &operator=(Form const &n);
		~Form();

		std::string	getName(void) const;
		size_t			getGradeForSignature() const;
		size_t			getGradeForExecution() const;
		bool		getSignedValue() const;
		void		beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
	private:
		std::string	_name;
		bool			_signed;
		size_t			_gradeForSignature;
		size_t			_gradeForExecution;
};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif

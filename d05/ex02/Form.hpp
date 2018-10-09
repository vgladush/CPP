/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:47:45 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/13 18:58:28 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class Form
{
	const std::string	name;
	bool				_signed;
	const int			gdSign;
	const int			gdExec;

public:

	struct		GradeTooHighException : std::exception {
		char const			*what() const throw();
	};

	struct		GradeTooLowException : std::exception {
		char const			*what() const throw();
	};

	struct		FormNotSignedException : std::exception {
		char const			*what() const throw();
	};

	Form(std::string const &name = "form", int sgn = 50, int ex = 50);
	Form(Form const &cpy);
	virtual ~Form();
	void			operator=(Form const &cpy);
	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;
	bool			getSigned() const;
	void			beSigned(Bureaucrat const &bur);
	virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, Form const &form);

#endif

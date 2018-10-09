/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 19:26:59 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	const std::string	name;
	int					grade;

	struct		GradeTooHighException : std::exception {
		char const			*what() const throw();
	};

	struct		GradeTooLowException : std::exception {
		char const			*what() const throw();
	};

public:

	Bureaucrat();
	Bureaucrat(std::string const &name, int gd);
	Bureaucrat(Bureaucrat const &cpy);
	~Bureaucrat();
	void		operator=(Bureaucrat const &cpy);
	void		increment(int nb);
	void		decrement(int nb);
	std::string	getName() const;
	int			getGrade() const;
	void		signForm(Form &form) const;

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bur);

#endif

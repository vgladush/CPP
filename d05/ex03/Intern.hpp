/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:39:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 17:58:12 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{

public:
	struct		NonExistentFormException : std::exception {
		char const			*what() const throw();
	};

	Intern();
	Intern(Intern const &cpy);
	~Intern();
	void	operator=(Intern const &cpy);
	Form	*makeForm(std::string name, std::string target);
	
};

#endif

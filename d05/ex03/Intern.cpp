/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:39:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 18:13:36 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &cpy) {
	(void)cpy;
}

Intern::~Intern() {}

void	Intern::operator=(Intern const &cpy) {
	(void)cpy;
}

char const	*Intern::NonExistentFormException::what() const throw() {
	return "this form does not exist";
}

Form	*Intern::makeForm(std::string name, std::string target) {
	Form	*fm = 0;
	if (name == "presidential pardon")
		fm = new PresidentialPardonForm(target);
	else if (name == "robotomy request")
		fm = new RobotomyRequestForm(target);
	else if (name == "shrubbery creation")
		fm = new ShrubberyCreationForm(target);
	else
		throw Intern::NonExistentFormException();
	return fm;
}

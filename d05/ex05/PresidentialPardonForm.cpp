/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 03:33:33 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 19:08:08 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) : Form(cpy) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy) {
	Form::operator=(cpy);
}

void	PresidentialPardonForm::execute(Bureaucrat const & bur) const {
	if (!this->getSigned())
		throw Form::FormNotSignedException();
	else if (this->getGradeExecute() < bur.getGrade())
		throw Form::GradeTooHighException();
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

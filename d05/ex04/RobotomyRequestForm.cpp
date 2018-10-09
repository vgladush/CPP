/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 03:33:33 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 14:52:20 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : Form(cpy) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy) {
	Form::operator=(cpy);
}

void	RobotomyRequestForm::execute(Bureaucrat const & bur) const {
	if (!this->getSigned())
		throw Form::FormNotSignedException();
	else if (this->getGradeExecute() < bur.getGrade())
		throw Form::GradeTooHighException();
	std::cout << "DrRrRrRrRr " << this->getName() <<
	(rand() % 2 ? " failed in an attempt to robotize."
	: " has been robotomized successfully") << std::endl;
}

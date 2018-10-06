/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 18:07:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int gd) : name(name) {
	if (gd < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gd > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = gd;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : name(cpy.name) {
	*this = cpy;
}

Bureaucrat::~Bureaucrat() {}

void		Bureaucrat::operator=(Bureaucrat const &cpy) {
	if (this != &cpy)
		this->grade = cpy.grade;
}

void		Bureaucrat::increment(int nb) {
	if (this->grade - nb < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= nb;
}

void		Bureaucrat::decrement(int nb) {
	if (this->grade + nb > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += nb;
}

std::string	Bureaucrat::getName() const {
	return this->name;
}

int			Bureaucrat::getGrade() const {
	return this->grade;
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "this bureaucrat is too low grade!";
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw() {	
	return "this bureaucrat is too high grade!";
}

void		Bureaucrat::signForm(Form &form) const {
	form.beSigned(*this);
	std::cout << this->name << " signs " << form.getName() << "." << std::endl;
}

void		Bureaucrat::executeForm(Form const & form) {
	form.execute(*this);
	std::cout << this->name << " executes " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bur) {
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return o;
}

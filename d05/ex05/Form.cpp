/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:47:45 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 19:14:18 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int sgn, int ex) : name(name), gdSign(sgn), gdExec(ex) {
	if (this->gdSign < 1 || this->gdExec < 1)
		throw Form::GradeTooHighException();
	else if (this->gdSign > 150 || this->gdExec > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form const &cpy) : name(cpy.name),  gdSign(cpy.gdSign), gdExec(cpy.gdExec) {
	*this = cpy;
}

Form::~Form() {}

void		Form::operator=(Form const &cpy) {
	if (this != &cpy)
		this->_signed = cpy._signed;
}

std::string	Form::getName() const {
	return this->name;
}

int			Form::getGradeSign() const {
	return this->gdSign;
}

int			Form::getGradeExecute() const {
	return this->gdExec;
}

bool		Form::getSigned() const {
	return this->_signed;
}

char const	*Form::GradeTooLowException::what(void) const throw() {
	return "this form is too low grade!";
}

char const	*Form::AlreadySignedFormException::what(void) const throw() {
	return "this form is already signed!";
}

char const	*Form::GradeTooHighException::what(void) const throw() {	
	return "this form is too high grade!";
}

char const	*Form::FormNotSignedException::what(void) const throw() {	
	return "this form is not signed!";
}

void		Form::beSigned(Bureaucrat const &bur) {
	if (bur.getGrade() > this->gdSign)
		throw Form::GradeTooHighException();
	if (this->_signed)
		throw Form::AlreadySignedFormException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &o, Form const &form) {
	o << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ")
	<< "signed. " << "Grade required to sign " << form.getGradeSign() <<
	", grade required to execute " << form.getGradeExecute() << "!" << std::endl;
	return o;
}

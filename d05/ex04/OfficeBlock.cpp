/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:01:16 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 19:10:50 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() {
	this->inr = 0;
	this->sign = 0;
	this->exec = 0;
}

OfficeBlock::OfficeBlock(Intern *inr, Bureaucrat *sigBur, Bureaucrat *exBur) :
	inr(inr), sign(sigBur), exec(exBur) {}

OfficeBlock::~OfficeBlock() {}

void	OfficeBlock::setIntern(Intern *inr) {
	this->inr = inr;
}

void	OfficeBlock::setSigningBureaucrat(Bureaucrat *sigBur) {
	this->sign = sigBur;
}

void	OfficeBlock::setExecutingBureaucrat(Bureaucrat *exBur) {
	this->exec = exBur;
}

char const	*OfficeBlock::NotThreeSpotsException::what() const throw() {
	return "not enough intern and/or bureaucrat";
}

void	OfficeBlock::doBureaucracy(std::string form, std::string target) {
	if (!this->inr || ! this->sign || !this->exec)
		throw OfficeBlock::NotThreeSpotsException();
	Form	*frm;
	frm = this->inr->makeForm(form, target);
	this->sign->signForm(*frm);
	this->exec->executeForm(*frm);
	delete frm;
}

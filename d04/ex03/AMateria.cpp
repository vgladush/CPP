/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 20:56:18 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type_(type) {
	this->xp_ = 0;
}

AMateria::AMateria(AMateria const & cpy) {
	*this = cpy;
}

void	AMateria::operator=(AMateria const &cpy) {
	this->xp_ = cpy.getXP();
	this->type_ = cpy.getType();
}

AMateria::~AMateria() {}

std::string const &	AMateria::getType() const {
	return this->type_;
}

unsigned int	AMateria::getXP() const {
	return this->xp_;
}


void	AMateria::use(ICharacter& target) {
	this->xp_ += 10;
	(void)target;
}

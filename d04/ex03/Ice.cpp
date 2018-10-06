/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 22:31:46 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const & cpy) : AMateria(cpy) {}

void	Ice::operator=(Ice const &cpy) {
	AMateria::operator=(cpy);
}

Ice::~Ice() {}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}

Ice*	Ice::clone() const {
	return new Ice();
}

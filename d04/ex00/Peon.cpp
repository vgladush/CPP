/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:02:35 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/31 00:03:17 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon &cpy) : Victim(cpy) {
	*this = cpy;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

void			Peon::operator=(const Peon & cpy) {
	this->name = cpy.getname();
}

void			Peon::getPolymorphed() const {
	std::cout << name << " has been turned into a pink pony !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, const Peon &cpy) {
	o << "I'm " << cpy.getname() << " and I like otters !" << std::endl;
	return o;
}

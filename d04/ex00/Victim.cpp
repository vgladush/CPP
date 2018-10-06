/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:02:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 23:58:25 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name) : name(name) {
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim &cpy) {
	*this = cpy;
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim() {
	std::cout << "Victim " << name << " just died for no apparent reason !" << std::endl;
}

std::string		Victim::getname() const {
	return this->name;
}

std::ostream	&operator<<(std::ostream &o, const Victim &cpy) {
	o << "I'm " << cpy.getname() << " and I like otters !" << std::endl;
	return o;
}

void			Victim::operator=(const Victim & cpy) {
	this->name = cpy.getname();
}

void			Victim::getPolymorphed() const {
	std::cout << name << " has been turned into a cute little sheep !" << std::endl;
}

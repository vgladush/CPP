/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/10 21:31:16 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : name(name),
damage(damage), ap(apcost) {}

AWeapon::AWeapon(AWeapon const &cpy) {
	*this = cpy;
}

void	AWeapon::operator=(const AWeapon & cpy) {
	this->name = cpy.getName();
	this->damage = cpy.getDamage();
	this->ap = cpy.getAPCost();
}

AWeapon::~AWeapon() {}

std::string const &	AWeapon::getName() const {
	return this->name;
}

int				AWeapon::getAPCost() const {
	return this->ap;
}

int				AWeapon::getDamage() const {
	return this->damage;
}

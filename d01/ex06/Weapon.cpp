/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:08:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 19:37:53 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string tp): type(tp) {}

Weapon::~Weapon() {};

const std::string	&Weapon::getType(void) {
	return (const std::string &)this->type;
}

void			Weapon::setType(std::string type) {
	this->type = type;
}

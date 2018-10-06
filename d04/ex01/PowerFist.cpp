/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 00:47:58 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const &cpy) : AWeapon("Power Fist", 8, 50) {
	*this = cpy;
}

void	PowerFist::operator=(const PowerFist & cpy) {
	AWeapon::operator=(cpy);
}

PowerFist::~PowerFist() {}

void	PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

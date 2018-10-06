/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 00:48:34 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &cpy) : AWeapon("Plasma Rifle", 5, 21) {
	*this = cpy;
}

void	PlasmaRifle::operator=(const PlasmaRifle & cpy) {
	AWeapon::operator=(cpy);
}

PlasmaRifle::~PlasmaRifle() {}

void	PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:39:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 18:19:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string tp) : type(tp) {}
ZombieEvent::~ZombieEvent() {}

Zombie	*ZombieEvent::newZombie(std::string name) {
	Zombie *zmb = new Zombie(name, this->type);
	return (zmb);
}

Zombie	*ZombieEvent::randomChump() {
	std::string nm[11] = {"Osel", "Pituh", "Olen", "Induck", "Gus", "Kozel", "Baran", "Ovca", "Kaban", "Ishak", "Los"};
	Zombie *zmb = newZombie(nm[rand() % 11]);
	zmb->announce();
	return (zmb);
}

void	ZombieEvent::setZombieType(std::string tp) {
	this->type = tp;
}

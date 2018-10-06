/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:08:04 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 20:09:44 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

Weapon	HumanA::dfweapon = Weapon();

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {};

HumanA::~HumanA() {};

void	HumanA::attack() {
	std::cout << this->name << " attacks with his "
	<< this->weapon->getType() << std::endl;
}

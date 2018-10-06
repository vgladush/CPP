/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:39:12 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 18:03:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name(name), type(type) {
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie died" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name << " (" << this->type << ") " << "Braiiiiiiinnnssss..." << std::endl;
}

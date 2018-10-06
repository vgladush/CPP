/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 01:21:27 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	this->typeCl = 4;
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 120;
	this->Max_energy_points = 120;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	std::string crt[6] = {"Hey everybody! Check out my package!", "Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?", "Recompiling my combat code!",
	"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!"};
	std::cout << "SP3R-TP created" << std::endl;
	std::cout << this->Name << ": \"" << crt[rand() % 6] << "\"" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &cpy) : ClapTrap(cpy), NinjaTrap(cpy), FragTrap(cpy)
{
	*this = cpy;
}

SuperTrap&	SuperTrap::operator = (const SuperTrap &cpy)
{
	this->typeCl = cpy.typeCl;
	this->Hit_points = cpy.Hit_points;
	this->Max_hit_points = cpy.Max_hit_points;
	this->Energy_points = cpy.Energy_points;
	this->Max_energy_points = cpy.Max_energy_points;
	this->Level = cpy.Level;
	this->Name = cpy.Name;
	this->Melee_attack_damage = cpy.Melee_attack_damage;
	this->Ranged_attack_damage = cpy.Ranged_attack_damage;
	this->Armor_damage_reduction = cpy.Armor_damage_reduction;
	return (*this);
}

SuperTrap::~SuperTrap()
{
	std::cout << "type SP3R-TP (came from NINJA-TP with FR4G-TP of CLAP-TP) "
	<< this->Name << " destroed" << std::endl;
	std::string dth[6] = {"Pop pop!", "Crit-i-cal!", "That looks like it hurts!", "WOW! I hit 'em!", "Extra ouch!", "Shwing!"};
	std::cout << this->Name << ": \"" << dth[rand() % 6] << "\"" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/10 21:13:10 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->typeCl = 1;
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 100;
	this->Max_energy_points = 100;
	this->Melee_attack_damage = 30;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	std::cout << "FR4G-TP created" << std::endl;
	std::string crt[6] = {"Hey everybody! Check out my package!", "Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?", "Recompiling my combat code!",
	"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!"};
	std::cout << this->Name << ": \"" << crt[rand() % 6] << "\"" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	*this = cpy;
}

FragTrap&	FragTrap::operator = (const FragTrap &cpy)
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

FragTrap::~FragTrap()
{
	std::cout << "type FR4G-TP ";
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string noenerg[10] = {"Where'd all my bullets go?", "Bullets are dumb.", "Who needs ammo anyway, am I right?", "I need tiny death pellets!",
	"Need some ammo!", "Dangit, I'm out!", "Ammo reserves are spent!", "Crap, no more shots left!", "Hnngh! Empty!", "Coming up empty!"};
	std::string att[7] = {"Clap-In-The-Box", "Gun Wizard", "Pirate Ship Mode", "One Shot Wonder", "Laser Inferno", "Meat Unicycle", "Torgue Fiesta"};
	if (this->Energy_points < 25)
		std::cout << this->Name << ": \"" << noenerg[rand() % 10] << "\"" << std::endl;
	else
	{
		int i = rand() % 7;
		this->Energy_points -= 25;
		std::cout << this->Name + " use \"" << att[i] << "\" attack and his energy decreased by 25 points. There are only " << this->Energy_points << " energy left!" << std::endl;
		if (i < 5)
			rangedAttack(target);
		else
			meleeAttack(target);
	}
}

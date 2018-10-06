/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 20:58:13 by vgladush         ###   ########.fr       */
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
	std::string crt[6] = {"Hey everybody! Check out my package!", "Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?", "Recompiling my combat code!",
	"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!"};
	std::cout << "FR4G-TP (" + this->Name + ") created" << std::endl;
	std::cout << this->Name << ": \"" << crt[rand() % 6] << "\"" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	this->typeCl = 1;
	std::cout << &cpy << " is copied into " << this << std::endl;
	*this = cpy;
}

FragTrap&	FragTrap::operator = (const FragTrap &cpy)
{
	this->typeCl = 1;
	this->Name = cpy.getName();
	this->Hit_points = cpy.getHp();
	this->Energy_points = cpy.getEp();
	this->Level = cpy.getLvl();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::string dth[6] = {"Pop pop!", "Crit-i-cal!", "That looks like it hurts!", "WOW! I hit 'em!", "Extra ouch!", "Shwing!"};
	std::cout << "FR4G-TP (" + this->Name + ") destroed" << std::endl;
	std::cout << this->Name << ": \"" << dth[rand() % 6] << "\"" << std::endl;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 23:38:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	this->typeCl = 3;
	this->Hit_points = 60;
	this->Max_hit_points = 60;
	this->Energy_points = 120;
	this->Max_energy_points = 120;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage = 5;
	this->Armor_damage_reduction = 0;
	std::string crt[6] = {"Hey everybody! Check out my package!", "Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?", "Recompiling my combat code!",
	"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!"};
	std::cout << "NINJA-TP created" << std::endl;
	std::cout << this->Name << ": \"" << crt[rand() % 6] << "\"" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &cpy) : ClapTrap(cpy)
{
	*this = cpy;
}

NinjaTrap&	NinjaTrap::operator = (const NinjaTrap &cpy)
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

NinjaTrap::~NinjaTrap()
{
	std::cout << "type NINJA-TP ";
}

int		NinjaTrap::choise_att(std::string target) {
	std::string noenerg[10] = {"Where'd all my bullets go?", "Bullets are dumb.", "Who needs ammo anyway, am I right?", "I need tiny death pellets!",
	"Need some ammo!", "Dangit, I'm out!", "Ammo reserves are spent!", "Crap, no more shots left!", "Hnngh! Empty!", "Coming up empty!"};
	std::string att[7] = {"Gun Wizard", "Pirate Ship Mode", "One Shot Wonder", "Laser Inferno", "Clap-In-The-Box", "Meat Unicycle", "Torgue Fiesta"};
	if (this->Energy_points < 21)
		std::cout << this->Name << ": \"" << noenerg[rand() % 10] << "\"" << std::endl;
	else
	{
		int i = rand() % 7;
		this->Energy_points -= 21;
		std::cout << "NINJA-TP " << this->Name << " use \"" << att[i] << "\" attack and his energy decreased by 21 points. There are only " << this->Energy_points << " energy left!" << std::endl;
		if (i < 4) {
			this->rangedAttack(target);
			return 1;
		}
		this->meleeAttack(target);
		return 2;
	}
	return (-1);
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & trap)
{
	int	i = choise_att(trap.getName());
	if (i == 1)
		trap.takeDamage(this->Ranged_attack_damage);
	else if (i == 2)
		trap.takeDamage(this->Melee_attack_damage);
}

void	NinjaTrap::ninjaShoebox(ScavTrap & trap)
{
	int	i = choise_att(trap.getName());
	if (i == 1)
		trap.takeDamage(this->Ranged_attack_damage);
	else if (i == 2)
		trap.takeDamage(this->Melee_attack_damage);
}

void	NinjaTrap::ninjaShoebox(FragTrap & trap)
{
	int	i = choise_att(trap.getName());
	if (i == 1)
		trap.takeDamage(this->Ranged_attack_damage);
	else if (i == 2)
		trap.takeDamage(this->Melee_attack_damage);
}

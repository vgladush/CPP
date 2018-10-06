/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:54:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 23:30:24 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Level(1), Name(name)
{
	std::cout << "CLAP-TP " << name << " type ";
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	*this = cpy;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap &cpy)
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

ClapTrap::~ClapTrap()
{
	std::cout << "CLAP-TP (" + this->Name + ") destroed" << std::endl;
	std::string dth[6] = {"Pop pop!", "Crit-i-cal!", "That looks like it hurts!", "WOW! I hit 'em!", "Extra ouch!", "Shwing!"};
	std::cout << this->Name << ": \"" << dth[rand() % 6] << "\"" << std::endl;
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	std::string rna[5] = {"Shaken, not stirred", "The moon is not enough!", "I'm Trap, Claptrap. Double oh... Trap.",
	"I expect you to die!", "I'd do anything for a woman with a gun."};
	if (this->typeCl == 1)
		std::cout << "FR4G-TP (";
	else if (this->typeCl == 2)
		std::cout << "SCAV-TP (";
	else
		std::cout << "NINJA-TP (";
	std::cout << this->Name << ") attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage !" << std::endl;
	std::cout << this->Name << ": \"" << rna[rand() % 5] << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::string mla[5] = {"This is why you do your homework!", "Pain school is now in session", "Guess who?", "Meet professor punch!", "Ready for the PUNCHline?!"};
	if (this->typeCl == 1)
		std::cout << "FR4G-TP (";
	else if (this->typeCl == 2)
		std::cout << "SCAV-TP (";
	else
		std::cout << "NINJA-TP (";
	std::cout << this->Name << ") attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage !" << std::endl;
	std::cout << this->Name << ": \"" << mla[rand() % 5] << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	double absorption = 100 * ((double)this->Armor_damage_reduction / ((double)this->Armor_damage_reduction + 300));
	absorption = (1 - (absorption / 100)) * amount;
	if (absorption > this->Hit_points)
		this->Hit_points = 0;
	else
		this->Hit_points -= (int)absorption;
	std::string ouch[7] = {"Why do I even feel pain?!", "Why did they build me out of galvanized flesh?!", "Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!", "Yikes! Ohhoho!", "Woah! Oh! Jeez!", "If only my chassis... weren't made of recycled human body parts! Wahahaha!"};
	if (this->typeCl == 1)
		std::cout << "FR4G-TP (";
	else if (this->typeCl == 2)
		std::cout << "SCAV-TP (";
	else
		std::cout << "NINJA-TP";
	std::cout << this->Name << ") received " << (int)absorption << " points of damage (" << amount << " dmg with considering "
	<< Armor_damage_reduction << " armor damage reduction). He had " << this->Hit_points << " hp left!" << std::endl;
	std::cout << this->Name << ": \"" << ouch[rand() % 7] << "\"" << std::endl;
	if (!this->Hit_points)
		this->~ClapTrap();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ((amount > this->Max_hit_points) || (this->Hit_points + amount > this->Max_hit_points))
		this->Hit_points = this->Max_hit_points;
	else
		this->Hit_points += amount;
	std::string gth[5] = {"Health! Eww, what flavor is red?", "Health over here!", "Sweet life juice!", "I found health!", "Healsies!"};
	std::cout << this->Name << ": \"" << gth[rand() % 5] << "\"" << std::endl;
	if (this->typeCl == 1)
		std::cout << "FR4G-TP (";
	else if (this->typeCl == 2)
		std::cout << "SCAV-TP (";
	else
		std::cout << "NINJA-TP";
	std::cout << this->Name << ") repaired " << amount << " hit points. He has " << this->Hit_points << " hp!" << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (this->Name);
}

void	ClapTrap::setName(std::string nm)
{
	this->Name = nm;
}

unsigned int	ClapTrap::getHp() const
{
	return (this->Hit_points);
}

unsigned int	ClapTrap::getEp() const
{
	return (this->Energy_points);
}

unsigned int	ClapTrap::getLvl() const
{
	return (this->Level);
}

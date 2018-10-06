/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 20:51:30 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int ScavTrap::Max_hit_points = 100;
unsigned int ScavTrap::Max_energy_points = 50;
unsigned int ScavTrap::Melee_attack_damage = 20;
unsigned int ScavTrap::Ranged_attack_damage = 15;
unsigned int ScavTrap::Armor_damage_reduction = 3;

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : Hit_points(100),	Energy_points(100), Level(1), Name(name)
{
	std::string crt[6] = {"Hey everybody! Check out my package!", "Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?", "Recompiling my combat code!",
	"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!"};
	std::cout << "SCAV-TP (" + this->Name + ") created" << std::endl;
	std::cout << this->Name << ": \"" << crt[rand() % 6] << "\"" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cpy)
{
	std::cout << &cpy << " is copied into " << this << std::endl;
	*this = cpy;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap &cpy)
{
	this->Name = cpy.getName();
	this->Hit_points = cpy.getHp();
	this->Energy_points = cpy.getEp();
	this->Level = cpy.getLvl();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::string dth[6] = {"Pop pop!", "Crit-i-cal!", "That looks like it hurts!", "WOW! I hit 'em!", "Extra ouch!", "Shwing!"};
	std::cout << "SCAV-TP (" + this->Name + ") destroed" << std::endl;
	std::cout << this->Name << ": \"" << dth[rand() % 6] << "\"" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::string rna[5] = {"Shaken, not stirred", "The moon is not enough!", "I'm Trap, Claptrap. Double oh... Trap.",
	"I expect you to die!", "I'd do anything for a woman with a gun."};
	std::cout << "SCAV-TP (" << this->Name << ") attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage !" << std::endl;
	std::cout << this->Name << ": \"" << rna[rand() % 5] << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::string mla[5] = {"This is why you do your homework!", "Pain school is now in session", "Guess who?", "Meet professor punch!", "Ready for the PUNCHline?!"};
	std::cout << "SCAV-TP (" << this->Name << ") attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage !" << std::endl;
	std::cout << this->Name << ": \"" << mla[rand() % 5] << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	double absorption = 100 * ((double)this->Armor_damage_reduction / ((double)this->Armor_damage_reduction + 300));
	absorption = (1 - (absorption / 100)) * amount;
	if (absorption > this->Hit_points)
		this->Hit_points = 0;
	else
		this->Hit_points -= (int)absorption;
	std::string ouch[7] = {"Why do I even feel pain?!", "Why did they build me out of galvanized flesh?!", "Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!", "Yikes! Ohhoho!", "Woah! Oh! Jeez!", "If only my chassis... weren't made of recycled human body parts! Wahahaha!"};
	std::cout << "SCAV-TP (" << this->Name << ") received " << (int)absorption << " points of damage (" << amount << " dmg with considering "
	<< Armor_damage_reduction << " armor damage reduction). He had " << this->Hit_points << " hp left!" << std::endl;
	std::cout << this->Name << ": \"" << ouch[rand() % 7] << "\"" << std::endl;
	if (!this->Hit_points)
		this->~ScavTrap();
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if ((amount > this->Max_hit_points) || (this->Hit_points + amount > this->Max_hit_points))
		this->Hit_points = this->Max_hit_points;
	else
		this->Hit_points += amount;
	std::string gth[5] = {"Health! Eww, what flavor is red?", "Health over here!", "Sweet life juice!", "I found health!", "Healsies!"};
	std::cout << this->Name << ": \"" << gth[rand() % 5] << "\"" << std::endl;
	std::cout << "SCAV-TP (" << this->Name << ") repaired " << amount << " hit points. He has " << this->Hit_points << " hp!" << std::endl;
}

std::string	ScavTrap::getName() const
{
	return (this->Name);
}

void	ScavTrap::setName(std::string nm)
{
	this->Name = nm;
}

unsigned int	ScavTrap::getHp() const
{
	return (this->Hit_points);
}

unsigned int	ScavTrap::getEp() const
{
	return (this->Energy_points);
}

unsigned int	ScavTrap::getLvl() const
{
	return (this->Level);
}

void	ScavTrap::challengeNewcomer()
{
	std::string act[8] = {"Miniontrap", "Funzerker", "Mechromagician", "Shhhh... Trap!", "Blight Bot", "Rubber Ducky", "Senseless Sacrifice", "Medbot"};
	std::string tk[8] = {"Claptrap throws out a Turrettrap that shoots explosive rockets (similar to Axton's Sabre Turret) and wields a Dahl assault rifle, periodically \
shooting powerful non-elemental bullets at its chosen target.", "Claptrap receives a copy of his currently equipped weapon in his other clamp, mimicking Salvador's Gunzerking ability.",
	"Claptrap summons a Punkbot, which engages enemies in combat in a similar fashion to Gaige's Deathtrap.", "Claptrap deploys a Holotrap and becomes invisible, similar to Zer0's \
Decepti0n ability.", "Claptrap summons a Sirentrap emitting an acid gas and with fire wings on its back, which proceeds to fly around enemies dealing incendiary and corrosive damage, \
similar to Maya's Blight Phoenix skill.", "Claptrap will continually bounce into the air and gain bullet reflection.", "Claptrap forces himself into Fight For Your Life to revive all \
other team members that are currently in Fight For Your Life.", "Claptrap gains drastically increased movement speed and a healing laser that he can use to restore teammate and enemy health."};
	int i = rand() % 8;
	std::cout << this->Name + " use " << act[i] << " : " << tk[i] << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/22 20:41:53 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int FragTrap::Max_hit_points = 100;
unsigned int FragTrap::Max_energy_points = 100;
unsigned int FragTrap::Melee_attack_damage = 30;
unsigned int FragTrap::Ranged_attack_damage = 20;
unsigned int FragTrap::Armor_damage_reduction = 5;

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : Hit_points(100),	Energy_points(100), Level(1), Name(name)
{
	std::string crt[6] = {"Hey everybody! Check out my package!", "Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?", "Recompiling my combat code!",
	"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!"};
	std::cout << "FR4G-TP (" + this->Name + ") created" << std::endl;
	std::cout << this->Name << ": \"" << crt[rand() % 6] << "\"" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy)
{
	std::cout << &cpy << " is copied into " << this << std::endl;
	*this = cpy;
}

FragTrap&	FragTrap::operator = (const FragTrap &cpy)
{
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

void	FragTrap::rangedAttack(std::string const & target)
{
	std::string rna[5] = {"Shaken, not stirred", "The moon is not enough!", "I'm Trap, Claptrap. Double oh... Trap.",
	"I expect you to die!", "I'd do anything for a woman with a gun."};
	std::cout << "FR4G-TP (" << this->Name << ") attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage !" << std::endl;
	std::cout << this->Name << ": \"" << rna[rand() % 5] << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::string mla[5] = {"This is why you do your homework!", "Pain school is now in session", "Guess who?", "Meet professor punch!", "Ready for the PUNCHline?!"};
	std::cout << "FR4G-TP (" << this->Name << ") attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage !" << std::endl;
	std::cout << this->Name << ": \"" << mla[rand() % 5] << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	double absorption = 100 * ((double)this->Armor_damage_reduction / ((double)this->Armor_damage_reduction + 300));
	absorption = (1 - (absorption / 100)) * amount;
	if (absorption > this->Hit_points)
		this->Hit_points = 0;
	else
		this->Hit_points -= (int)absorption;
	std::string ouch[7] = {"Why do I even feel pain?!", "Why did they build me out of galvanized flesh?!", "Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!", "Yikes! Ohhoho!", "Woah! Oh! Jeez!", "If only my chassis... weren't made of recycled human body parts! Wahahaha!"};
	std::cout << "FR4G-TP (" << this->Name << ") received " << (int)absorption << " points of damage (" << amount << " dmg with considering "
	<< Armor_damage_reduction << " armor damage reduction). He had " << this->Hit_points << " hp left!" << std::endl;
	std::cout << this->Name << ": \"" << ouch[rand() % 7] << "\"" << std::endl;
	if (!this->Hit_points)
		this->~FragTrap();
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if ((amount > this->Max_hit_points) || (this->Hit_points + amount > this->Max_hit_points))
		this->Hit_points = this->Max_hit_points;
	else
		this->Hit_points += amount;
	std::string gth[5] = {"Health! Eww, what flavor is red?", "Health over here!", "Sweet life juice!", "I found health!", "Healsies!"};
	std::cout << this->Name << ": \"" << gth[rand() % 5] << "\"" << std::endl;
	std::cout << "FR4G-TP (" << this->Name << ") repaired " << amount << " hit points. He has " << this->Hit_points << " hp!" << std::endl;
}

std::string	FragTrap::getName() const
{
	return (this->Name);
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

void	FragTrap::setName(std::string nm)
{
	this->Name = nm;
}

unsigned int	FragTrap::getHp() const
{
	return (this->Hit_points);
}

unsigned int	FragTrap::getEp() const
{
	return (this->Energy_points);
}

unsigned int	FragTrap::getLvl() const
{
	return (this->Level);
}

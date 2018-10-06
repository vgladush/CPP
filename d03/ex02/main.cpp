/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:01 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/22 20:39:57 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	srand(time(0));
	FragTrap ftbot1 = FragTrap("Lucas");
	FragTrap ftbot2 = FragTrap(ftbot1);
	ftbot2.setName("Dick");
	ScavTrap bot1 = ScavTrap("Dude");
	ScavTrap bot2 = ScavTrap(bot1);
	bot2.setName("Duck");

	ftbot1.takeDamage(50);
	ftbot1.beRepaired(80);
	ftbot2.meleeAttack("Zombie");
	ftbot2.rangedAttack("Pony");
	ftbot1.vaulthunter_dot_exe(ftbot2.getName());
	ftbot1.vaulthunter_dot_exe(ftbot2.getName());
	ftbot1.vaulthunter_dot_exe(ftbot2.getName());
	ftbot2.takeDamage(40);
	ftbot2.beRepaired(10);
	ftbot2.takeDamage(90);
	ftbot1.vaulthunter_dot_exe(ftbot2.getName());
	ftbot1.vaulthunter_dot_exe(ftbot2.getName());
	ftbot1.vaulthunter_dot_exe(ftbot2.getName());

	bot1.takeDamage(50);
	bot1.beRepaired(80);
	bot2.meleeAttack("Zombie");
	bot2.rangedAttack("Pony");
	bot1.challengeNewcomer();
	bot1.challengeNewcomer();
	bot1.challengeNewcomer();
	bot2.takeDamage(40);
	bot2.beRepaired(10);
	bot2.takeDamage(90);
	bot1.challengeNewcomer();
	bot1.challengeNewcomer();
	bot1.challengeNewcomer();
}

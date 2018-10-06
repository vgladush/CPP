/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:01 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/22 17:58:27 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main()
{
	srand(time(0));
	FragTrap ftbot1 = FragTrap("Lucas");
	FragTrap ftbot2 = FragTrap(ftbot1);

	ftbot2.setName("Dick");
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
}

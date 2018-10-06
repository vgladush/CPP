/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:01 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 01:47:16 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

int		main()
{
	srand(time(0));
	FragTrap ft = FragTrap("Lucas");
	ScavTrap st = ScavTrap("Dude");
	NinjaTrap nt("Rooster");
	SuperTrap zd("Cock");

	nt.ninjaShoebox(ft);
	ft.beRepaired(90);
	zd.ninjaShoebox(ft);
	ft.beRepaired(30);
	ft.vaulthunter_dot_exe("Rook");
	zd.vaulthunter_dot_exe("Don");

	return 0;
}

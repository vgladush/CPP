/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:01 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 23:36:30 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

int		main()
{
	srand(time(0));
	FragTrap ft = FragTrap("Lucas");
	ScavTrap st = ScavTrap("Dude");
	NinjaTrap nt("Rooster");
	NinjaTrap zd = nt;
	zd.setName("Cock");

	zd.ninjaShoebox(ft);
	zd.ninjaShoebox(st);
	ft.beRepaired(50);
	zd.ninjaShoebox(nt);
	st.beRepaired(20);
	zd.ninjaShoebox(ft);
	zd.ninjaShoebox(st);
	zd.ninjaShoebox(ft);
	zd.ninjaShoebox(ft);

	return 0;
}

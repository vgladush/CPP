/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:37:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 18:28:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main() {
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	std::cout << std::endl <<std::endl;
	{
		ISpaceMarine* Rock = new TacticalMarine;
		ISpaceMarine* Joshua = new AssaultTerminator;
		ISpaceMarine* Din = Rock->clone();
		ISquad* sqd = new Squad;
		std::cout << "begin : " << sqd->getCount() << std::endl;
		sqd->push(Rock);
		sqd->push(Joshua);
		sqd->push(Din);
		std::cout << "added 3 new : " << sqd->getCount() << std::endl;
		sqd->push(Rock);
		sqd->push(Joshua);
		sqd->push(Din);
		std::cout << "added 3 old : " << sqd->getCount() << std::endl;
		for (int i = 0; i < sqd->getCount(); ++i)
		{
			ISpaceMarine* cur = sqd->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete sqd;
	}

	return 0;
}
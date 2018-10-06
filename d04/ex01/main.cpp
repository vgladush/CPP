/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 01:24:23 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int main()
{
	{
		Character* zaz = new Character("zaz");
		std::cout << *zaz;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pf);
		zaz->attack(b);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		delete zaz;
		delete b;
		delete pr;
		delete pf;
	}
	std::cout << std::endl << std::endl;
	{
		Character *Fred = new Character("Fred");
		Character *Jack = new Character("Jack");
		PowerFist *pow = new PowerFist();
		PlasmaRifle *plaz = new PlasmaRifle();
		SuperMutant *mut = new SuperMutant();
		RadScorpion *scorp = new RadScorpion();

		std::cout << *Fred << *Jack;

		Fred->equip(pow);
		Jack->equip(plaz);

		std::cout << *Fred << *Jack;

		Fred->attack(mut);
		Fred->attack(mut);

		Jack->attack(scorp);
		Jack->attack(scorp);

		std::cout << *Fred << *Jack;

		Fred->recoverAP();
		Jack->recoverAP();
		Jack->recoverAP();

		std::cout << *Fred << *Jack;

		Fred->attack(mut);
		Fred->attack(mut);

		Jack->attack(scorp);
		Jack->attack(scorp);

		std::cout << *Fred << *Jack;

		delete Fred;
		delete Jack;
		delete pow;
		delete plaz;
		delete mut;
		delete scorp;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:39:43 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 18:18:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int			main(void)
{
	Zombie	zom1;
	Zombie	zom2;

	zom1.announce();
	zom2.announce();
	
	ZombieEvent wer;
	Zombie *zom3 = wer.randomChump();
	wer.setZombieType("Smart");
	Zombie *zom4 = wer.randomChump();
	Zombie *zom5 = wer.randomChump();
	wer.setZombieType("Hungry");
	Zombie *zom6 = wer.randomChump();
	Zombie *zom7 = wer.randomChump();

	delete (zom3);
	delete (zom4);
	delete (zom5);
	delete (zom6);
	delete (zom7);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 14:14:35 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

int main() {
	MiningBarge *barge = new MiningBarge();
	IAsteroid *ast1 = new BocalSteroid();
	IAsteroid *ast2 = new AsteroBocal();
	IMiningLaser *las1 = new DeepCoreMiner();
	IMiningLaser *las2 = new StripMiner();

	//without laser
	barge->mine(ast1);

	std::cout << std::endl;
	
	//1 laser 1 target total 1 stting
	barge->equip(las1);
	barge->mine(ast2);

	std::cout << std::endl;
	//2 lasers 2 targets total 4 sttings
	barge->equip(las2);
	barge->mine(ast1);
	barge->mine(ast2);
	delete barge;
	delete ast1;
	delete ast2;
	delete las1;
	delete las2;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:58:42 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 18:40:39 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"


ZombieHorde::ZombieHorde(int N) {
	this->zmb = new Zombie[N];
	this->nb = N;

	std::string nm[11] = {"Osel", "Pituh", "Olen", "Induck", "Gus", "Kozel", "Baran", "Ovca", "Kaban", "Ishak", "Los"};
	for (int i = 0; i < N; i++)
		this->zmb[i].name = nm[rand() % 11];
}

ZombieHorde::~ZombieHorde() {
		delete [] this->zmb;
}

void	ZombieHorde::announce() {
	for (int i = 0; i < this->nb; i++)
		this->zmb[i].announce();
}

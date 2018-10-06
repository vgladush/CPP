/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 14:15:08 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

MiningBarge::MiningBarge() {
	this->laser[0] = 0;
	this->laser[1] = 0;
	this->laser[2] = 0;
	this->laser[3] = 0;
}

MiningBarge::MiningBarge(MiningBarge const &bar) {
	*this = bar;
}

MiningBarge::~MiningBarge() {}

void	MiningBarge::operator=(MiningBarge const &bar) {
	for (int i = 0; i < 4; ++i) {
		this->laser[i] = bar.laser[i];
	}
}

void	MiningBarge::equip(IMiningLaser* las) {
	for (int i = 0; i < 4; ++i) {
		if (!this->laser[i]) {
			this->laser[i] = las;
			break ;
		}
	}
}

void	MiningBarge::mine(IAsteroid* ast) const {
	if (!this->laser[0]) {
		std::cout << "* Barge without lasers ! *" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i) {
		if (!this->laser[i])
			break ;
		this->laser[i]->mine(ast);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 00:23:58 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : hp(hp), type(type) {}

Enemy::Enemy(Enemy const &cpy) {
	*this = cpy;
}

void	Enemy::operator=(const Enemy & cpy) {
	this->hp = cpy.getHP();
	this->type = cpy.getType();
}

Enemy::~Enemy() {}

std::string const &	Enemy::getType() const {
	return this->type;
}

int				Enemy::getHP() const {
	return this->hp;
}

void	Enemy::takeDamage(int dmg) {
	if (dmg < 0)
		dmg = 0;
	if (this->hp > dmg)
		this->hp -= dmg;
	else
		this->hp = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:23:20 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"

Ship::Ship() {
	this->x = 3;
	this->y = 24;
	this->hot = false;
}

Ship::~Ship() {}

Ship::Ship(Ship &cpy) {
	*this = cpy;
}

Ship& Ship::operator=(Ship &cpy) {
	this->x = cpy.x;
	this->y = cpy.y;
	return *this;
}

void	Ship::moveShip(int mv) {
	if (mv == 1) {
		if (this->y - 1)
			this->y--;
	} else if (mv == 2) {
		if (this->y + 1 < 48)
			this->y++;
	} else if (mv == 3) {
		if (this->x - 2 > 0)
			this->x -= 2;
	} else {
		if (this->x + 2 < 155)
			this->x += 2;
	}
}

void	Ship::actShip(WINDOW *win) {
	mvwprintw(win, this->y - 1, this->x, "[+)");
	mvwprintw(win, this->y, this->x, "[+|}");
	mvwprintw(win, this->y + 1, this->x, "[+)");
	for (int i = 0; i < BULLETS; ++i)
		this->bullets[i].actBullets(win);
}

void	Ship::createBullet() {
	for (int i = 0; i < BULLETS; i++) {
		if (!this->bullets[i].act) {
			for (int j = 0; j < BULLETS; j++)
				if (this->bullets[j].act && bullets[j].x < this->x + 6 && j != i)
					return ;
			this->bullets[i].act = true;
			this->bullets[i].x = this->x + 4;
			this->bullets[i].y = this->y;
			if (i == BULLETS - 1)
				this->hot = true;
			break ;
		}
	}
}

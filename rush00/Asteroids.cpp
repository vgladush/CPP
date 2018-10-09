/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:21:36 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroids.hpp"

Asteroids::Asteroids() {
	this->x = 1 + rand() % (WIDTH - 2);
	this->y = rand() % HEIGHT;
	this->ast = 0;
	this->act = 0;
}

Asteroids::~Asteroids() {}

Asteroids::Asteroids(Asteroids &cpy) {
	*this = cpy;
}

Asteroids& Asteroids::operator=(Asteroids &cpy) {
	this->x = cpy.x;
	this->y = cpy.y;
	return *this;
}

void	Asteroids::actAsteroids(WINDOW * win, bool s, bool b) {
	if (this->act == 1) {
		int j = 1 + rand() % 3;
		if (this->ast == 1 || (j == 1 && !this->ast)) {
			this->ast = 1;
			mvwprintw(win, this->y - 1, this->x, "***");
			mvwprintw(win, this->y, this->x - 1, "*****");
			mvwprintw(win, this->y + 1, this->x, "***");
		} else if (this->ast == 2 || (j == 2 && !this->ast)) {
			this->ast = 2;
			mvwprintw(win, this->y - 1, this->x, "***");
			mvwaddch(win, this->y, this->x + 1, '*');
			mvwprintw(win, this->y + 1, this->x, "***");
		} else {
			this->ast = 3;
			mvwaddch(win, this->y - 1, this->x, '*');
			mvwprintw(win, this->y, this->x - 1, "***");
			mvwaddch(win, this->y + 1, this->x, '*');
		}
	} else if (this->act == 2) {
		if (this->ast == 1) {
			mvwaddch(win, this->y - 2, this->x - 1, '*');
			mvwprintw(win, this->y - 1, this->x - 3, "*   *");
			mvwprintw(win, this->y, this->x - 5, "* * * * *");
			mvwprintw(win, this->y + 1, this->x - 3, "*   *");
			mvwaddch(win, this->y + 2, this->x - 1, '*');
		} else if (this->ast == 2) {
			this->ast = 2;
			mvwprintw(win, this->y - 2, this->x - 2, "* * *");
			mvwaddch(win, this->y, this->x, '*');
			mvwprintw(win, this->y + 2, this->x - 2, "* * *");
		} else {
			this->ast = 3;
			mvwaddch(win, this->y - 2, this->x - 1, '*');
			mvwprintw(win, this->y, this->x - 3, "* * *");
			mvwaddch(win, this->y + 2, this->x - 1, '*');
		}
	} else if (this->act == 3) {
		if (this->ast == 1) {
			mvwaddch(win, this->y - 3, this->x - 3, '.');
			mvwprintw(win, this->y - 2, this->x - 6, ".     .");
			mvwprintw(win, this->y, this->x - 9, ".  .  .  .  .");
			mvwprintw(win, this->y + 2, this->x - 6, ".     .");
			mvwaddch(win, this->y + 3, this->x - 3, '.');
		} else if (this->ast == 2) {
			this->ast = 2;
			mvwprintw(win, this->y - 3, this->x - 4, ".  .  .");
			mvwaddch(win, this->y, this->x - 1, '.');
			mvwprintw(win, this->y + 3, this->x - 4, ".  .  .");
		} else {
			this->ast = 3;
			mvwaddch(win, this->y - 3, this->x - 2, '.');
			mvwprintw(win, this->y, this->x - 5, ".  .  .");
			mvwaddch(win, this->y + 3, this->x - 2, '.');
		}
	}
	if (s) {
		if (this->act == 2)
			this->act = 3;
		else if (this->act == 3) {
			this->act = 0;
			this->ast = 0;
		}
		this->x--;
		if (this->x < -2) {
			this->x = WIDTH;
			this->y = rand() % HEIGHT;
			this->act = (b ? 0 : 1);
			this->ast = 0;
		}
	}
}

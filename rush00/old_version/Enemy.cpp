/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:20 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:21:56 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() {
	this->x = rand() % WIDTH;
	this->y = rand() % HEIGHT;
	this->hp = 2;
	this->exist = 0;
}

Enemy::~Enemy() {}

Enemy::Enemy(Enemy &cpy) {
	*this = cpy;
}

Enemy& Enemy::operator=(Enemy &cpy) {
	this->x = cpy.x;
	this->y = cpy.y;
	return *this;
}

void	Enemy::actEnemy(WINDOW *win, const int &t) {
	if (!(t % 2))
		this->x -= rand() % 2;
	if (!(t % 24)) {
		if (this->exist == 2)
			this->exist = 3;
		else if (this->exist == 3) {
			this->exist = 0;
			this->x = 10;
		}
		int r = this->y + (1 - rand() % 3);
		this->y += (r > HEIGHT - 3 || r < 1 ? this->y - r : r - this->y);
	}
	if (this->x < 0) {
		this->x = WIDTH - 4;
		this->y = 1 + rand() % (HEIGHT - 2);
		this->exist = 1;
	}
	if (this->exist == 1) {
		mvwprintw(win, this->y, this->x, "{X]");
	} else if (this->exist == 2) {
		mvwprintw(win, this->y - 1, this->x, "-");
		mvwprintw(win, this->y, this->x - 2, "{ x ]");
		mvwprintw(win, this->y + 1, this->x, "-");
	} else if (this->exist == 3) {
		mvwprintw(win, this->y - 2, this->x - 2, ".");
		mvwprintw(win, this->y, this->x - 6, ".   .   .");
		mvwprintw(win, this->y + 2, this->x - 2, ".");
	}
}

void	Enemy::moveBoss() {
	if (this->x > WIDTH - 15) {
		this->x--;
		if (this->x == WIDTH - 10)
			this->exist = 2;
	} else {
		int r = this->y + (1 - rand() % 3);
		this->y += (r > HEIGHT - 10 || r < 0 ? this->y - r : r - this->y);
	}
}

void	Enemy::printBoss(WINDOW *win) {
	if (this->exist < 3 && this->x < WIDTH - 4) {
		mvwprintw(win, this->y, this->x, "(XX]");
		mvwprintw(win, this->y + 1, this->x - 1, "(XXX]");
		mvwprintw(win, this->y + 2, this->x - 2, "(XXXX]");
		mvwprintw(win, this->y + 3, this->x - 3, "(XXXXX]");
		mvwprintw(win, this->y + 4, this->x - 4, "(<XXXXX]");
		mvwprintw(win, this->y + 5, this->x - 3, "(XXXXX]");
		mvwprintw(win, this->y + 6, this->x - 2, "(XXXX]");
		mvwprintw(win, this->y + 7, this->x - 1, "(XXX]");
		mvwprintw(win, this->y + 8, this->x, "(XX]");
	} else if (this->exist == 1) {
		if (this->x < WIDTH - 3) {
			mvwprintw(win, this->y, this->x, "(XX");
			mvwprintw(win, this->y + 1, this->x - 1, "(XXX");
			mvwprintw(win, this->y + 2, this->x - 2, "(XXXX");
			mvwprintw(win, this->y + 3, this->x - 3, "(XXXXX");
			mvwprintw(win, this->y + 4, this->x - 4, "(<XXXXX");
			mvwprintw(win, this->y + 5, this->x - 3, "(XXXXX");
			mvwprintw(win, this->y + 6, this->x - 2, "(XXXX");
			mvwprintw(win, this->y + 7, this->x - 1, "(XXX");
			mvwprintw(win, this->y + 8, this->x, "(XX");
		} else if (this->x < WIDTH - 2) {
			mvwprintw(win, this->y, this->x, "(X");
			mvwprintw(win, this->y + 1, this->x - 1, "(XX");
			mvwprintw(win, this->y + 2, this->x - 2, "(XXX");
			mvwprintw(win, this->y + 3, this->x - 3, "(XXXX");
			mvwprintw(win, this->y + 4, this->x - 4, "(<XXXX");
			mvwprintw(win, this->y + 5, this->x - 3, "(XXXX");
			mvwprintw(win, this->y + 6, this->x - 2, "(XXX");
			mvwprintw(win, this->y + 7, this->x - 1, "(XX");
			mvwprintw(win, this->y + 8, this->x, "(X");
		} else if (this->x < WIDTH - 1) {
			mvwprintw(win, this->y, this->x, "(");
			mvwprintw(win, this->y + 1, this->x - 1, "(X");
			mvwprintw(win, this->y + 2, this->x - 2, "(XX");
			mvwprintw(win, this->y + 3, this->x - 3, "(XXX");
			mvwprintw(win, this->y + 4, this->x - 4, "(<XXX");
			mvwprintw(win, this->y + 5, this->x - 3, "(XXX");
			mvwprintw(win, this->y + 6, this->x - 2, "(XX");
			mvwprintw(win, this->y + 7, this->x - 1, "(X");
			mvwprintw(win, this->y + 8, this->x, "(");
		} else if (this->x < WIDTH) {
			mvwprintw(win, this->y + 1, this->x - 1, "(");
			mvwprintw(win, this->y + 2, this->x - 2, "(X");
			mvwprintw(win, this->y + 3, this->x - 3, "(XX");
			mvwprintw(win, this->y + 4, this->x - 4, "(<XX");
			mvwprintw(win, this->y + 5, this->x - 3, "(XX");
			mvwprintw(win, this->y + 6, this->x - 2, "(X");
			mvwprintw(win, this->y + 7, this->x - 1, "(");
		} else {
			mvwprintw(win, this->y + 2, this->x - 2, "(");
			mvwprintw(win, this->y + 3, this->x - 3, "(X");
			mvwprintw(win, this->y + 4, this->x - 4, "(<X");
			mvwprintw(win, this->y + 5, this->x - 3, "(X");
			mvwprintw(win, this->y + 6, this->x - 2, "(");
		}
	} else if (this->exist == 3) {
		mvwprintw(win, this->y - 4, this->x - 4, ". x x .");
		mvwprintw(win, this->y - 2, this->x - 5, ". x x x .");
		mvwprintw(win, this->y, this->x - 6, ". x x x x .");
		mvwprintw(win, this->y + 2, this->x - 8, ". x x x x x .");
		mvwprintw(win, this->y + 4, this->x - 9, ". . x x x x x .");
		mvwprintw(win, this->y + 6, this->x - 8, ". x x x x x .");
		mvwprintw(win, this->y + 8, this->x - 6, ". x x x x .");
		mvwprintw(win, this->y + 10, this->x - 5, ". x x x .");
		mvwprintw(win, this->y + 12, this->x - 4, ". x x .");
	} else if (this->exist == 4) {
		mvwprintw(win, this->y - 8, this->x - 6, ".   .");
		mvwprintw(win, this->y - 5, this->x - 8, ".   x   .");
		mvwprintw(win, this->y - 2, this->x - 10, ".   x   x   .");
		mvwprintw(win, this->y + 1, this->x - 12, ".   x   x   x   .");
		mvwprintw(win, this->y + 4, this->x - 12, ".   x   x   x   .");
		mvwprintw(win, this->y + 7, this->x - 12, ".   x   x   x   .");
		mvwprintw(win, this->y + 10, this->x - 10, ".   x   x   .");
		mvwprintw(win, this->y + 13, this->x - 8, ".   x   .");
		mvwprintw(win, this->y + 15, this->x - 6, ".   .");
	} else {
		mvwprintw(win, this->y - 8, this->x - 6, ".");
		mvwprintw(win, this->y - 4, this->x - 8, ".     .");
		mvwprintw(win, this->y, this->x - 12, ".     .     .");
		mvwprintw(win, this->y + 4, this->x - 12, ".     .     .");
		mvwprintw(win, this->y + 8, this->x - 12, ".     .     .");
		mvwprintw(win, this->y + 12, this->x - 8, ".     .");
		mvwprintw(win, this->y + 16, this->x - 6, ".");
	}
}

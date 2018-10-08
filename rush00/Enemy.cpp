/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:45:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Enemy::Enemy() 
{
	this->_x = rand() % WIDTH;
	this->_y = rand() % HEIGHT;
	this->hp = 2;
	this->_act = 0;
	return;
}

Enemy::~Enemy() 
{
	return;
}

Enemy::Enemy(Enemy &cpy) 
{
	*this = cpy;
	return;
}

Enemy& Enemy::operator=(Enemy &cpy)
{
	this->_act = cpy._act;
	this->_x = cpy._x;
	this->_y = cpy._y;
	return *this;
}

void	Enemy::actEnemy(WINDOW *win, const int &t)
{
	if (!(t % 2))
		this->_x -= rand() % 2;
	if (!(t % 24)) 
	{
		if (this->_act == 2)
			this->_act = 3;
		else if (this->_act == 3) 
		{
			this->_act = 0;
			this->_x = 10;
		}
		int r = this->_y + (1 - rand() % 3);
		this->_y += (r > HEIGHT - 3 || r < 1 ? this->_y - r : r - this->_y);
	}
	if (this->_x < 0)
	 {
		this->_x = WIDTH - 4;
		this->_y = 1 + rand() % (HEIGHT - 2);
		this->_act = 1;
	}
	if (this->_act == 1) 
	{
		mvwprintw(win, this->_y, this->_x, "{X]");
	}
	else if (this->_act == 2)
	{
		mvwprintw(win, this->_y - 1, this->_x, "-");
		mvwprintw(win, this->_y, this->_x - 2, "{ x ]");
		mvwprintw(win, this->_y + 1, this->_x, "-");
	} 
	else if (this->_act == 3) 
	{
		mvwprintw(win, this->_y - 2, this->_x - 2, ".");
		mvwprintw(win, this->_y, this->_x - 6, ".   .   .");
		mvwprintw(win, this->_y + 2, this->_x - 2, ".");
	}
	return;
}

void	Enemy::moveBoss() 
{
	if (this->_x > WIDTH - 15) 
	{
		this->_x--;
		if (this->_x == WIDTH - 10)
			this->_act = 2;
	} 
	else 
	{
		int r = this->_y + (1 - rand() % 3);
		this->_y += (r > HEIGHT - 10 || r < 0 ? this->_y - r : r - this->_y);
	}
	return;
}

void	Enemy::printBoss(WINDOW *win) 
{
	if (this->_act < 3 && this->_x < WIDTH - 4) 
	{
		mvwprintw(win, this->_y, this->_x, "(XX]");
		mvwprintw(win, this->_y + 1, this->_x - 1, "(XXX]");
		mvwprintw(win, this->_y + 2, this->_x - 2, "(XXXX]");
		mvwprintw(win, this->_y + 3, this->_x - 3, "(XXXXX]");
		mvwprintw(win, this->_y + 4, this->_x - 4, "(<XXXXX]");
		mvwprintw(win, this->_y + 5, this->_x - 3, "(XXXXX]");
		mvwprintw(win, this->_y + 6, this->_x - 2, "(XXXX]");
		mvwprintw(win, this->_y + 7, this->_x - 1, "(XXX]");
		mvwprintw(win, this->_y + 8, this->_x, "(XX]");
	} 
	else if (this->_act == 1) 
	{
		if (this->_x < WIDTH - 3) 
		{
			mvwprintw(win, this->_y, this->_x, "(XX");
			mvwprintw(win, this->_y + 1, this->_x - 1, "(XXX");
			mvwprintw(win, this->_y + 2, this->_x - 2, "(XXXX");
			mvwprintw(win, this->_y + 3, this->_x - 3, "(XXXXX");
			mvwprintw(win, this->_y + 4, this->_x - 4, "(<XXXXX");
			mvwprintw(win, this->_y + 5, this->_x - 3, "(XXXXX");
			mvwprintw(win, this->_y + 6, this->_x - 2, "(XXXX");
			mvwprintw(win, this->_y + 7, this->_x - 1, "(XXX");
			mvwprintw(win, this->_y + 8, this->_x, "(XX");
		} 
		else if (this->_x < WIDTH - 2) 
		{
			mvwprintw(win, this->_y, this->_x, "(X");
			mvwprintw(win, this->_y + 1, this->_x - 1, "(XX");
			mvwprintw(win, this->_y + 2, this->_x - 2, "(XXX");
			mvwprintw(win, this->_y + 3, this->_x - 3, "(XXXX");
			mvwprintw(win, this->_y + 4, this->_x - 4, "(<XXXX");
			mvwprintw(win, this->_y + 5, this->_x - 3, "(XXXX");
			mvwprintw(win, this->_y + 6, this->_x - 2, "(XXX");
			mvwprintw(win, this->_y + 7, this->_x - 1, "(XX");
			mvwprintw(win, this->_y + 8, this->_x, "(X");
		} 
		else if (this->_x < WIDTH - 1) 
		{
			mvwprintw(win, this->_y, this->_x, "(");
			mvwprintw(win, this->_y + 1, this->_x - 1, "(X");
			mvwprintw(win, this->_y + 2, this->_x - 2, "(XX");
			mvwprintw(win, this->_y + 3, this->_x - 3, "(XXX");
			mvwprintw(win, this->_y + 4, this->_x - 4, "(<XXX");
			mvwprintw(win, this->_y + 5, this->_x - 3, "(XXX");
			mvwprintw(win, this->_y + 6, this->_x - 2, "(XX");
			mvwprintw(win, this->_y + 7, this->_x - 1, "(X");
			mvwprintw(win, this->_y + 8, this->_x, "(");
		} 
		else if (this->_x < WIDTH) 
		{
			mvwprintw(win, this->_y + 1, this->_x - 1, "(");
			mvwprintw(win, this->_y + 2, this->_x - 2, "(X");
			mvwprintw(win, this->_y + 3, this->_x - 3, "(XX");
			mvwprintw(win, this->_y + 4, this->_x - 4, "(<XX");
			mvwprintw(win, this->_y + 5, this->_x - 3, "(XX");
			mvwprintw(win, this->_y + 6, this->_x - 2, "(X");
			mvwprintw(win, this->_y + 7, this->_x - 1, "(");
		} 
		else 
		{
			mvwprintw(win, this->_y + 2, this->_x - 2, "(");
			mvwprintw(win, this->_y + 3, this->_x - 3, "(X");
			mvwprintw(win, this->_y + 4, this->_x - 4, "(<X");
			mvwprintw(win, this->_y + 5, this->_x - 3, "(X");
			mvwprintw(win, this->_y + 6, this->_x - 2, "(");
		}
	} 
	else if (this->_act == 3) 
	{
		mvwprintw(win, this->_y - 4, this->_x - 4, ". x x .");
		mvwprintw(win, this->_y - 2, this->_x - 5, ". x x x .");
		mvwprintw(win, this->_y, this->_x - 6, ". x x x x .");
		mvwprintw(win, this->_y + 2, this->_x - 8, ". x x x x x .");
		mvwprintw(win, this->_y + 4, this->_x - 9, ". . x x x x x .");
		mvwprintw(win, this->_y + 6, this->_x - 8, ". x x x x x .");
		mvwprintw(win, this->_y + 8, this->_x - 6, ". x x x x .");
		mvwprintw(win, this->_y + 10, this->_x - 5, ". x x x .");
		mvwprintw(win, this->_y + 12, this->_x - 4, ". x x .");
	} 
	else if (this->_act == 4) 
	{
		mvwprintw(win, this->_y - 8, this->_x - 6, ".   .");
		mvwprintw(win, this->_y - 5, this->_x - 8, ".   x   .");
		mvwprintw(win, this->_y - 2, this->_x - 10, ".   x   x   .");
		mvwprintw(win, this->_y + 1, this->_x - 12, ".   x   x   x   .");
		mvwprintw(win, this->_y + 4, this->_x - 12, ".   x   x   x   .");
		mvwprintw(win, this->_y + 7, this->_x - 12, ".   x   x   x   .");
		mvwprintw(win, this->_y + 10, this->_x - 10, ".   x   x   .");
		mvwprintw(win, this->_y + 13, this->_x - 8, ".   x   .");
		mvwprintw(win, this->_y + 15, this->_x - 6, ".   .");
	} else 
	{
		mvwprintw(win, this->_y - 8, this->_x - 6, ".");
		mvwprintw(win, this->_y - 4, this->_x - 8, ".     .");
		mvwprintw(win, this->_y, this->_x - 12, ".     .     .");
		mvwprintw(win, this->_y + 4, this->_x - 12, ".     .     .");
		mvwprintw(win, this->_y + 8, this->_x - 12, ".     .     .");
		mvwprintw(win, this->_y + 12, this->_x - 8, ".     .");
		mvwprintw(win, this->_y + 16, this->_x - 6, ".");
	}
	return;
}

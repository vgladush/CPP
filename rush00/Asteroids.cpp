/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:44 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:45:36 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Asteroids::Asteroids() : Position()
{
	this->_x = 1 + rand() % (WIDTH - 2);
	this->_y = rand() % HEIGHT;
	this->ast = 0;
	this->_act = 0;
}

Asteroids::~Asteroids() 
{
	return;
}

Asteroids::Asteroids(Asteroids &cpy)
{
	*this = cpy;
	return;
}

Asteroids& Asteroids::operator=(Asteroids &cpy) 
{
	this->_x = cpy._x;
	this->_y = cpy._y;
	return *this;
}

void	Asteroids::actAsteroids(WINDOW * win, bool s, bool b) 
{
	if (this->_act == 1) 
	{
		int j = 1 + rand() % 3;
		if (this->ast == 1 || (j == 1 && !this->ast))
		{
			this->ast = 1;
			mvwprintw(win, this->_y - 1, this->_x, "***");
			mvwprintw(win, this->_y, this->_x - 1, "*****");
			mvwprintw(win, this->_y + 1, this->_x, "***");
		} else if (this->ast == 2 || (j == 2 && !this->ast)) 
		{
			this->ast = 2;
			mvwprintw(win, this->_y - 1, this->_x, "***");
			mvwaddch(win, this->_y, this->_x + 1, '*');
			mvwprintw(win, this->_y + 1, this->_x, "***");
		} else 
		{
			this->ast = 3;
			mvwaddch(win, this->_y - 1, this->_x, '*');
			mvwprintw(win, this->_y, this->_x - 1, "***");
			mvwaddch(win, this->_y + 1, this->_x, '*');
		}
	} 
	else if (this->_act == 2) 
	{
		if (this->ast == 1) 
		{
			mvwaddch(win, this->_y - 2, this->_x - 1, '*');
			mvwprintw(win, this->_y - 1, this->_x - 3, "*   *");
			mvwprintw(win, this->_y, this->_x - 5, "* * * * *");
			mvwprintw(win, this->_y + 1, this->_x - 3, "*   *");
			mvwaddch(win, this->_y + 2, this->_x - 1, '*');
		} 
		else if (this->ast == 2)
		{
			this->ast = 2;
			mvwprintw(win, this->_y - 2, this->_x - 2, "* * *");
			mvwaddch(win, this->_y, this->_x, '*');
			mvwprintw(win, this->_y + 2, this->_x - 2, "* * *");
		} else 
		{
			this->ast = 3;
			mvwaddch(win, this->_y - 2, this->_x - 1, '*');
			mvwprintw(win, this->_y, this->_x - 3, "* * *");
			mvwaddch(win, this->_y + 2, this->_x - 1, '*');
		}
	} 
	else if (this->_act == 3) 
	{
		if (this->ast == 1) 
		{
			mvwaddch(win, this->_y - 3, this->_x - 3, '.');
			mvwprintw(win, this->_y - 2, this->_x - 6, ".     .");
			mvwprintw(win, this->_y, this->_x - 9, ".  .  .  .  .");
			mvwprintw(win, this->_y + 2, this->_x - 6, ".     .");
			mvwaddch(win, this->_y + 3, this->_x - 3, '.');
		}
		else if (this->ast == 2) 
		{
			this->ast = 2;
			mvwprintw(win, this->_y - 3, this->_x - 4, ".  .  .");
			mvwaddch(win, this->_y, this->_x - 1, '.');
			mvwprintw(win, this->_y + 3, this->_x - 4, ".  .  .");
		} else 
		{
			this->ast = 3;
			mvwaddch(win, this->_y - 3, this->_x - 2, '.');
			mvwprintw(win, this->_y, this->_x - 5, ".  .  .");
			mvwaddch(win, this->_y + 3, this->_x - 2, '.');
		}
	}
	if (s) 
	{
		if (this->_act == 2)
			this->_act = 3;
		else if (this->_act == 3) 
		{
			this->_act = 0;
			this->ast = 0;
		}
		this->_x--;
		if (this->_x < -2) 
		{
			this->_x = WIDTH;
			this->_y = rand() % HEIGHT;
			this->_act = (b ? 0 : 1);
			this->ast = 0;
		}
	}
	return;
}

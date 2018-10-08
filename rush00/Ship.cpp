/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:41:48 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:46:21 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Ship::Ship() : Position()
{
	this->_x = 3;
	this->_y = 24;
	this->hot = false;
	return;
}

Ship::~Ship() 
{
	return;
}

Ship::Ship(Ship &cpy) 
{
	*this = cpy;
	return;
}

Ship& Ship::operator=(Ship &cpy) 
{
	this->_x = cpy._x;
	this->_y = cpy._y;
	return *this;
}

void	Ship::moveShip(int mv) 
{
	if (mv == 1) 
	{
		if (this->_y - 1 > 1)
			this->_y--;
	} 
	else if (mv == 2) 
	{
		if (this->_y + 1 < 48)
			this->_y++;
	} 
	else if (mv == 3) 
	{
		if (this->_x - 2 > 0)
			this->_x -= 2;
	} else 
	{
		if (this->_x + 2 < 155)
			this->_x += 2;
	}
	return;
}

void	Ship::actShip(WINDOW *win) 
{
	mvwprintw(win, this->_y - 1, this->_x, "[+)");
	mvwprintw(win, this->_y, this->_x, "[+|}");
	mvwprintw(win, this->_y + 1, this->_x, "[+)");
	for (int i = 0; i < BULLETS; ++i)
		this->bullets[i].actBullets(win);
	return;
}

void	Ship::createBullet() 
{
	for (int i = 0; i < BULLETS; i++) 
	{
		if (!this->bullets[i].act) 
		{
			for (int j = 0; j < BULLETS; j++)
				if (this->bullets[j].act && bullets[j].x < this->_x + 6 && j != i)
					return ;
			this->bullets[i].act = true;
			this->bullets[i].x = this->_x + 4;
			this->bullets[i].y = this->_y;
			if (i == BULLETS - 1)
				this->hot = true;
			break ;
		}
	}
	return;
}

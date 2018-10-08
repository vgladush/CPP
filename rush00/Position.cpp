/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:39 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:46:13 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Position::Position() 
{
	this->_x = 0;
	this->_y = 0;
	this->_act = 0;
	return;
}

Position::~Position() 
{
	return;
}

Position::Position(Position &cpy) 
{
	*this = cpy;
	return;
}

Position& Position::operator=(Position &cpy) 
{
	this->_x = cpy._x;
	this->_y = cpy._y;
	this->_act = cpy._act;
	return *this;
}

	int Position:: getX()
	{
		return (this->_x);
	}
	int Position:: getY()
	{
		return (this->_y);
	}
	int Position:: getA()
	{
		return (this->_act);
	}

	void Position::setX(int x)
	{
		this->_x = x;
		return;
	}
	void Position::setY(int y)
	{
		this->_y = y;
		return;
	}
	void Position::setA(int act)
	{
		this->_act = act;
		return; 
	}


// void	Position::actPosition(WINDOW *win, bool s) 
// {
// 	if (s) 
// 	{
// 		--this->x;
// 		if (!this->x) 
// 		{
// 			this->x = WIDTH - 2;
// 			this->y = 1 + rand() % (HEIGHT - 2);
// 		}
// 	}
// 	mvwaddch(win, this->y, this->x, '.');
// 	return;
// }
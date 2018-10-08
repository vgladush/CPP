/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:42:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:46:26 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Stars::Stars() : Position()
{
	this->_x = 1 + rand() % (WIDTH - 2);
	this->_y = 1 + rand() % (HEIGHT - 2);
	return;
}

Stars::~Stars() 
{
	return;
}

Stars::Stars(Stars &cpy) 
{
	*this = cpy;
	return;
}

Stars& Stars::operator=(Stars &cpy) 
{
	this->_x = cpy._x;
	this->_y = cpy._y;
	return *this;
}

void	Stars::actStars(WINDOW *win, bool s) 
{
	if (s) 
	{
		--this->_x;
		if (!this->_x) 
		{
			this->_x = WIDTH - 2;
			this->_y = 1 + rand() % (HEIGHT - 2);
		}
	}
	mvwaddch(win, this->_y, this->_x, '.');
	return;
}

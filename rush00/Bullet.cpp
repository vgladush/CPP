/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:47 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:45:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Bullet::Bullet() 
{
    act = false;
    x = 0;
    y = 0;
    return;
}

Bullet::~Bullet() 
{
	return;
}

Bullet::Bullet(Bullet &cpy) 
{
    *this = cpy;
    return;
}

Bullet& Bullet::operator=(Bullet &cpy) 
{
    this->x = cpy.x;
    this->y = cpy.y;
    return *this;
}

void	Bullet::actBullets(WINDOW *win) 
{
	if (!this->act)
		return ;
	if (this->x < WIDTH - 2) 
	{
		mvwprintw(win, this->y, this->x, "->");
		this->x += 1;
	} 
	else
	{
		this->act = false;
	}
	return;
}

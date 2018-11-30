/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:20 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:21:42 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet() {
    act = false;
    x = 0;
    y = 0;
}

Bullet::~Bullet() {}

Bullet::Bullet(Bullet &cpy) {
    *this = cpy;
}

Bullet& Bullet::operator=(Bullet &cpy) {
    this->x = cpy.x;
    this->y = cpy.y;
    return *this;
}

void	Bullet::actBullets(WINDOW *win) {
	if (!this->act)
		return ;
	if (this->x < WIDTH - 2) {
		mvwprintw(win, this->y, this->x, "->");
		this->x += 1;
	} else
		this->act = false;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:23:24 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stars.hpp"

Stars::Stars() {
	this->x = 1 + rand() % (WIDTH - 2);
	this->y = 1 + rand() % (HEIGHT - 2);
}

Stars::~Stars() {}

Stars::Stars(Stars &cpy) {
	*this = cpy;
}

Stars& Stars::operator=(Stars &cpy) {
	this->x = cpy.x;
	this->y = cpy.y;
	return *this;
}

void	Stars::actStars(WINDOW *win, bool s) {
	if (s) {
		--this->x;
		if (!this->x) {
			this->x = WIDTH - 2;
			this->y = 1 + rand() % (HEIGHT - 2);
		}
	}
	mvwaddch(win, this->y, this->x, '.');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:23:22 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
#define SHIP_HPP

#include "Constants.hpp"

class Ship {
public:
	Ship();
	~Ship();
	Ship(Ship &cpy);
	Ship &operator=(Ship & cpy);

	void	moveShip(int mv);
	void	actShip(WINDOW *win);
	void	createBullet();

	Bullet	bullets[BULLETS];
	int		x;
	int		y;
	bool	hot;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:42:04 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:46:24 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
#define SHIP_HPP

class Ship : public Position
{
	public:
	Ship();
	~Ship();
	Ship(Ship &cpy);
	Ship &operator=(Ship & cpy);
	///////
	void	moveShip(int mv);
	void	actShip(WINDOW *win);
	void	createBullet();

	Bullet	bullets[BULLETS];
	bool	hot;
};

#endif

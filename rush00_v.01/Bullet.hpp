/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:20 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:21:49 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Constants.hpp"

#ifndef BULLET_HPP
#define BULLET_HPP

class Bullet {
public:
	Bullet();
	Bullet(Bullet & cpy);
	Bullet &operator=(Bullet & cpy);
	void	actBullets(WINDOW *win);

	~Bullet();
	int x;
	int y;
	bool act;
};

#endif

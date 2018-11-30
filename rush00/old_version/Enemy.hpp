/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:20 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:22:33 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Constants.hpp"

class Enemy {
public:
	Enemy();
	Enemy(Enemy & cpy);
	~Enemy();
	Enemy &operator=(Enemy & cpy);
	void	moveBoss();
	void	printBoss(WINDOW *win);
	void	actEnemy(WINDOW *win, const int &t);

	int exist;
	int x;
	int y;
	int hp;
};

#endif

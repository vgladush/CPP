/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:50 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:45:58 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy : public Position
{	
	public:
	Enemy();
	Enemy(Enemy & cpy);
	~Enemy();
	Enemy &operator=(Enemy & cpy);
	void	moveBoss();
	void	printBoss(WINDOW *win);
	void	actEnemy(WINDOW *win, const int &t);

	int hp;
};

#endif

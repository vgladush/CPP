/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:48 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:45:49 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

class Bullet
{	
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

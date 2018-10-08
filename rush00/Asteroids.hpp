/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:21:38 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include "Constants.hpp"

class Asteroids {
public:
	Asteroids();
	~Asteroids();
	Asteroids(Asteroids & cpy);
	Asteroids &operator=(Asteroids & cpy);
	void	actAsteroids(WINDOW * win, bool s, bool b);
	int x;
	int y;
	int	ast;
	int act;
};

#endif

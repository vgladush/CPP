/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:44:46 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:45:40 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

class Asteroids : public Position
{
	public:
	
	Asteroids();
	~Asteroids();
	Asteroids(Asteroids & cpy);
	Asteroids &operator=(Asteroids & cpy);
	void	actAsteroids(WINDOW * win, bool s, bool b);
	
	int	ast;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 00:22:23 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy
{
private:
	int			hp;
	std::string	type;

public:
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const &cpy);
	void	operator=(const Enemy & cpy);
	virtual ~Enemy();
	std::string const & getType() const;
	int getHP() const;
	virtual void takeDamage(int dmg);
	
};

#endif

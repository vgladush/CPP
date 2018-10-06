/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:58:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/03 16:11:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE
#define ZOMBIE_HORDE

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int N = 1);
	~ZombieHorde();

	void	announce();

private:
	int		nb;
	Zombie	*zmb;
};

#endif

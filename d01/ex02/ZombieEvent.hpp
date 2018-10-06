/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:39:30 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 18:13:12 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT
#define ZOMBIE_EVENT

# include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent(std::string tp = "old");
	~ZombieEvent();

	void	setZombieType(std::string tp);
	Zombie	*randomChump(void);

private:
	Zombie	*newZombie(std::string name);
	std::string type;
};

#endif

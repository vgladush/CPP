/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 14:06:49 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINING_BARGE
#define MINING_BARGE

#include "KoalaSteroid.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"
#include "AsteroKreog.hpp"

class MiningBarge
{
	IMiningLaser *laser[4];
public:
	MiningBarge();
	MiningBarge(MiningBarge const &bar);
	~MiningBarge();
	void	operator=(MiningBarge const &bar);
	void	equip(IMiningLaser* las);
	void	mine(IAsteroid* ast) const;
};

#endif

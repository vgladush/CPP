/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 13:57:45 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIP_MINER
#define STRIP_MINER

#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
public:
	StripMiner();
	StripMiner(StripMiner const & cpy);
	~StripMiner();
	void	operator=(StripMiner const & cpy);
	void	mine(IAsteroid* ast);
	
};

#endif

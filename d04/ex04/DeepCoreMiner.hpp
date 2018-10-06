/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 13:57:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEP_CORE_MINER
#define DEEP_CORE_MINER

#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner();
	DeepCoreMiner(DeepCoreMiner const & cpy);
	~DeepCoreMiner();
	void	operator=(DeepCoreMiner const & cpy);
	void	mine(IAsteroid* ast);
	
};

#endif

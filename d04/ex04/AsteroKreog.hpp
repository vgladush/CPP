/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 12:15:37 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERO_BOCAL
#define ASTERO_BOCAL

#include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid
{
public:
	AsteroBocal();
	AsteroBocal(AsteroBocal const &cpy);
	~AsteroBocal();
	void		operator=(AsteroBocal const &cpy);
	std::string	beMined(DeepCoreMiner * las) const;
	std::string	beMined(StripMiner * las) const;
	std::string	getName() const;

};

#endif

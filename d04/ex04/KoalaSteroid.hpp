/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 13:19:18 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOCAL_STEROID
#define BOCAL_STEROID

#include "IAsteroid.hpp"

class BocalSteroid : public IAsteroid
{
public:
	BocalSteroid();
	BocalSteroid(BocalSteroid const &cpy);
	~BocalSteroid();
	void		operator=(BocalSteroid const &cpy);
	std::string	beMined(DeepCoreMiner * las) const;
	std::string	beMined(StripMiner * las) const;
	std::string	getName() const;

};

#endif

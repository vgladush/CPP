/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 12:22:07 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid() {}

BocalSteroid::BocalSteroid(BocalSteroid const &cpy) {
	(void)cpy;
}

BocalSteroid::~BocalSteroid() {}

void		BocalSteroid::operator=(BocalSteroid const &cpy) {
	(void)cpy;
}

std::string	BocalSteroid::beMined(DeepCoreMiner * las) const {
	(void)las;
	return "Zazium";
}

std::string	BocalSteroid::beMined(StripMiner * las) const {
	(void)las;
	return "Krpite";
}

std::string	BocalSteroid::getName() const {
	return "BocalSteroid";
}

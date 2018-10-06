/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 12:20:49 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal() {}

AsteroBocal::AsteroBocal(AsteroBocal const &cpy) {
	(void)cpy;
}

AsteroBocal::~AsteroBocal() {}

void		AsteroBocal::operator=(AsteroBocal const &cpy) {
	(void)cpy;
}

std::string	AsteroBocal::beMined(DeepCoreMiner * las) const {
	(void)las;
	return "Thorite";
}

std::string	AsteroBocal::beMined(StripMiner * las) const {
	(void)las;
	return "Flavium";
}

std::string	AsteroBocal::getName() const {
	return "AsteroBocal";
}

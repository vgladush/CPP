/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:12:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/12 14:07:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner() {}

StripMiner::StripMiner(StripMiner const & cpy) {
	(void)cpy;
}

StripMiner::~StripMiner() {}

void	StripMiner::operator=(StripMiner const & cpy) {
	(void)cpy;
}

void	StripMiner::mine(IAsteroid* ast) {
	std::cout << "* strip mining ... got " << ast->beMined(this) << " ! *" << std::endl;
}

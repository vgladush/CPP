/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:35:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 19:24:03 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : IQ(90) {}

Brain::~Brain() {}

std::string Brain::identify(void) const {
	std::ostringstream adress;
	adress << (void const *)this;
	return adress.str();
}

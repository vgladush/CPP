/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:34:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 19:27:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {}

Human::~Human() {}

const Brain	&Human::getBrain() {
	return this->brain;
}

std::string	Human::identify() const {
	return this->brain.identify();
}

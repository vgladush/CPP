/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:37:01 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 17:25:36 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & sqd) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	(void)sqd;
}

void	TacticalMarine::operator=(TacticalMarine const & sqd) {
	(void)sqd;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine*	TacticalMarine::clone() const {
	return new TacticalMarine(*this);
}

void	TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void	TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}
void	TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

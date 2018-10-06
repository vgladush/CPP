/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:34:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 21:24:29 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target) {
	std::cout << "Use attack (melee) on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "Use attack (ranged) on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "Use intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {
	typedef void (Human::*How_atk)(std::string const &);
	How_atk atks[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string	varis[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	for (int i = 0; i < 3; ++i) {
		if (action_name == varis[i]) {
			(this->*atks[i])(target);
			break ;
		}
	}
}

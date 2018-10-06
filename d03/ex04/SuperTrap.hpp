/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:07 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 01:20:56 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_TRAP
#define SUPER_TRAP

#include "NinjaTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
public:
	SuperTrap(std::string name = "Bot");
	SuperTrap(SuperTrap const &cpy);
	~SuperTrap();

	SuperTrap&	operator = (const SuperTrap &cpy);
};

#endif

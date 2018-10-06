/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:07 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 01:07:38 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP
#define SCAV_TRAP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(std::string name = "Bot");
	ScavTrap(ScavTrap const &cpy);
	~ScavTrap();

	void		challengeNewcomer();
	ScavTrap&	operator = (const ScavTrap &cpy);
};

#endif

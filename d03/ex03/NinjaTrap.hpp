/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:07 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 22:49:35 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP
#define NINJA_TRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
public:
	NinjaTrap(std::string name = "Bot");
	NinjaTrap(NinjaTrap const &cpy);
	~NinjaTrap();

	NinjaTrap&	operator = (const NinjaTrap &cpy);
	void		ninjaShoebox(NinjaTrap & trap);
	void		ninjaShoebox(ScavTrap & trap);
	void		ninjaShoebox(FragTrap & trap);

private:
	int			choise_att(std::string target);
};

#endif

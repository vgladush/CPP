/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:07 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 00:45:51 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP
#define FRAG_TRAP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap(std::string name = "Bot");
	FragTrap(FragTrap const &cpy);
	~FragTrap();

	void		vaulthunter_dot_exe(std::string const & target);
	FragTrap&	operator = (const FragTrap &cpy);
};

#endif

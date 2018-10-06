/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:39:07 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/22 20:39:37 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP
#define FRAG_TRAP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(std::string name = "Bot");
	FragTrap(FragTrap const &cpy);
	~FragTrap();

	void		vaulthunter_dot_exe(std::string const & target);
	FragTrap&	operator = (const FragTrap &cpy);
};

#endif

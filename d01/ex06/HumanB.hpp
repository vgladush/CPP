/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:25:36 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 20:11:20 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

# include "Weapon.hpp"

class	HumanB	{
	private:
		std::string		name;
		Weapon			*weapon;

	public:
		HumanB(std::string name = "Jack");
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon &weapon);
} ;

#endif

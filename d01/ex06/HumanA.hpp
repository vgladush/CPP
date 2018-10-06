/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:25:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 20:12:30 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

# include "Weapon.hpp"

class	HumanA	{
	private:
		static Weapon	dfweapon;
		std::string		name;
		Weapon			*weapon;

	public:
		HumanA(std::string name = "John", Weapon &weapon = HumanA::dfweapon);
		~HumanA(void);

		void	attack(void);
} ;

#endif

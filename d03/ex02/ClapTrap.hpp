/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:54:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 20:54:58 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Clap_TRAP
#define Clap_TRAP

# include <iostream>
# include <ctime>
# include <cstdlib>

class ClapTrap
{
protected:
	unsigned int	typeCl;
	unsigned int	Hit_points;
	unsigned int	Max_hit_points;
	unsigned int	Energy_points;
	unsigned int	Max_energy_points;
	unsigned int	Level;
	std::string		Name;
	unsigned int	Melee_attack_damage;
	unsigned int	Ranged_attack_damage;
	unsigned int	Armor_damage_reduction;

public:
	ClapTrap(std::string name = "Bot");
	ClapTrap(ClapTrap const &cpy);
	~ClapTrap();

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			setName(std::string nm);
	ClapTrap&		operator = (const ClapTrap &cpy);
	std::string		getName() const;
	unsigned int	getHp() const;
	unsigned int	getEp() const;
	unsigned int	getLvl() const;
};

#endif

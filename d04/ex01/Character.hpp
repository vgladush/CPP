/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 00:21:29 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	std::string	name;
	AWeapon		*weap;
	int			ap;

public:
	Character(std::string const & name);
	Character(Character const &cpy);
	void	operator=(const Character & cpy);
	~Character();
	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
	AWeapon const *	getWeapon() const;
	int		getAP() const;
	std::string const & getName() const;

};

std::ostream	&operator<<(std::ostream &o, Character const & chr);

#endif

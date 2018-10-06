/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:51:57 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 00:21:50 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon
{
private:
	std::string	name;
	int			damage;
	int			ap;

public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &cpy);
	void	operator=(const AWeapon & cpy);
	virtual ~AWeapon();
	std::string const &	getName() const;
	int				getAPCost() const;
	int				getDamage() const;
	virtual void	attack() const = 0;

};

#endif

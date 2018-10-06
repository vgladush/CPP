/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:04:02 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/20 14:18:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

# include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string tp = "Pistol");
	~Weapon();

	const std::string	&getType();
	void	setType(std::string type);
};

#endif

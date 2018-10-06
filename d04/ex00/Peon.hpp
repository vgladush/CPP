/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:02:35 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/09 21:16:36 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	Peon(Peon &cpy);
	~Peon();

	void 	getPolymorphed() const;

	void	operator=(const Peon & cpy);
};

std::ostream	&operator<<(std::ostream &o, const Peon &cpy);

#endif

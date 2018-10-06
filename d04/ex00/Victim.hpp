/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:02:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 23:07:46 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
public:
	Victim(std::string name);
	Victim(Victim &cpy);
	virtual ~Victim();
	
	std::string		getname() const;

	virtual void	getPolymorphed() const;

	void			operator=(const Victim & cpy);

protected:
	std::string name;
};

std::ostream	&operator<<(std::ostream &o, const Victim &cpy);

#endif

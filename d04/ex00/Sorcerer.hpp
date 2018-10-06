/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:02:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 23:30:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SORCERER_HPP
#define	SORCERER_HPP

#include "Peon.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer &cpy);
	~Sorcerer();

	std::string	getname() const;
	std::string	gettitle() const;

	void	operator=(const Sorcerer & cpy);

	void	polymorph(Victim const &vic) const;

private:
	std::string	name;
	std::string	title;
	
};

std::ostream	&operator<<(std::ostream &o, const Sorcerer &cpy);

#endif

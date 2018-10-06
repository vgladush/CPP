/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:36:37 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 17:31:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"

#ifndef SQUAD_HPP
#define SQUAD_HPP

class Squad : public ISquad
{
	int				count;
	ISpaceMarine	**unit;

public:
	Squad();
	Squad(Squad const & sqd);
	void	operator=(Squad const & sqd);
	~Squad();
	int getCount() const;
	ISpaceMarine* getUnit(int nb) const;
	int push(ISpaceMarine* mar);

};

#endif

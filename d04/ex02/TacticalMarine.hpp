/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:36:37 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 17:27:52 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"

#ifndef TACTICAL_MARINE
#define TACTICAL_MARINE

class TacticalMarine : public ISpaceMarine
{

public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const & sqd);
	void	operator=(TacticalMarine const & sqd);
	~TacticalMarine();
	TacticalMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

};

#endif

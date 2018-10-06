/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:37:01 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 17:27:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"

#ifndef ASSAULT_TERMINATOR
#define ASSAULT_TERMINATOR

class AssaultTerminator : public ISpaceMarine
{

public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const & sqd);
	void	operator=(AssaultTerminator const & sqd);
	~AssaultTerminator();
	AssaultTerminator* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

};

#endif

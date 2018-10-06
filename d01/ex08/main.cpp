/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:35:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 21:22:16 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main()
{
	Human chel;

	chel.action("meleeAttack", "Frog");
	chel.action("rangedAttack", "Duck");
	chel.action("intimidatingShout", "Fool");

	return (0);
}

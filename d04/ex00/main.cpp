/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:02:35 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/31 00:03:22 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

int	main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	std::cout << std::endl << std::endl;
	{
		Sorcerer	src("Richard", "wizard");
		Victim		vic("Mark");
		Victim		vic2("Scot");
		Peon		pn("Frog");
		Peon		pn2(pn);

		std::cout << src << vic << vic2;

		vic2 = vic;

		src.polymorph(vic);
		src.polymorph(vic2);
		src.polymorph(pn);
		src.polymorph(pn2);
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:39:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 00:33:37 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

static void	ponyOnTheHeap(void)
{
	Pony	*hp = new Pony;
	delete hp;
}

static void	ponyOnTheStack(void)
{
	Pony	st;
}

int			main(void)
{
	std::cout << "creating heap Pony" << std::endl;
	ponyOnTheHeap();
	std::cout << "creating stack Pony" << std::endl;
	ponyOnTheStack();
	return (0);
}

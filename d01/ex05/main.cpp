/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:35:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 21:19:24 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human bob;
	
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	
	Human John;
	Human Max;
	
	std::cout << John.identify() << std::endl;
	std::cout << John.getBrain().identify() << std::endl;
	std::cout << Max.identify() << std::endl;
	std::cout << Max.getBrain().identify() << std::endl;
	return (0);
}

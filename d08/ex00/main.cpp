/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:07:02 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 16:57:11 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int		main()
{
	std::vector<int> i{10, 42, 65, 78, 90, 15, 7, 396, 802, 44};

	try {

		std::cout << *easyfind(i, 15) << std::endl;
		std::cout << *easyfind(i, 42) << std::endl;
		std::cout << *easyfind(i, 100) << std::endl;
		std::cout << *easyfind(i, 7) << std::endl;
	}
	catch (std::exception & a) {
		std::cout << a.what() << std::endl;
	}
}

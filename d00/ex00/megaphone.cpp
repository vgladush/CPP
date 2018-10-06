/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 21:49:33 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/23 20:44:04 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; av[i][j]; j++) {
				if (av[i][j] < 123 && av[i][j] > 96)
					av[i][j] -= 32;
			}
			std::cout << av[i];
		}
		std::cout << std:: endl;
	}
	return 0;
}

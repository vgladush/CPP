/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:01:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/27 23:34:19 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <fstream>

int	main(int ac, char **av) {
	std::string	content;
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			std::ifstream	ifs(av[i]);
			if (ifs.good() == true) {
				while (ifs.eof() == false) {
					std::string buf;
					getline(ifs, buf);
					buf.push_back('\n');
					content += buf;
				}
			} else
				std::cout << "Can not open file: " << av[i] << std::endl;
		}
	}
	while (1) {
		std::string buf;
		if (!getline(std::cin, buf))
			break ;
		buf.push_back('\n');
		content += buf;
	}
	std::cout << content << std::endl;
	return 0;
}

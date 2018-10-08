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
	std::string buf;
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			std::ifstream	ifs(av[i]);
			if (ifs.good() == true) {
				while (ifs.eof() == false) {
					getline(ifs, buf);
					buf.push_back('\n');
					content += buf;
				}
			} else
				std::cerr << "Can not open file or it is a directory" << av[i] << std::endl;
		}
		std::cout << content;
	}
	else {
		while (1) {
			std::string buf;
			if (!getline(std::cin, buf))
				break ;
			std::cout << buf << std::endl;
		}
	}
	return 0;
}

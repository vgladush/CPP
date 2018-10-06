/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:00:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 00:11:36 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

void		out_char(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void		what_is(std::string s)
{
	if (s.size() == 1 && (s[0] > 57 || s[0] < 48)) {
		out_char(s[0]);
		return ;
	}
	try {
		int i = std::stoi(s);
		std::cout << "int: " << i << std::endl;
		if (std::isprint(i))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} catch(...) {
		std::cout << "int: impossible" << std::endl;
		std::cout << "char: impossible" << std::endl;
	}
	try	{
		float f = std::stof(s);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} catch(...) {
		std::cout << "float: nanf" << std::endl;
	}
	try	{
		double d = std::stod(s);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	} catch(...) {
		std::cout << "double: nan" << std::endl;
	}
}

int		main(int ac, char const **av)
{
	if (ac != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	else if (av[1])
		what_is(av[1]);
	return 0;
}

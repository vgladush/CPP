/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:44:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 15:38:41 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<double> s(6);

	try {
		s[0] = 15.18;
		s[1] = 121.56;
		s[2] = 5559.8713;
		s[3] = 146.2379;
		s[4] = 42.424242;
		s[5] = 67138.6811;
		s[6] = 42.12;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	for (unsigned int i = 0; i < s.size(); ++i) {
		std::cout << s[i] << std::endl;
	}

	Array<double> ar(s);

	s[5] = 59.888;
	std::cout << s[5] << " != " << ar[5] << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/13 03:14:18 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bur("low", 120);

	std::cout << bur;
	bur.increment(15);
	std::cout << bur;
	bur.decrement(45);	
	std::cout << bur;

	try {
		bur.decrement(1);
		bur.decrement(1);
		bur.decrement(0);
		bur.decrement(1);

		std::cout << "Exception's did't work" << std::endl;

	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}
	try {
		Bureaucrat bur2("hight", 0);

		std::cout << "Exception's did't work" << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}

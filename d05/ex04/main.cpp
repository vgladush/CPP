/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 19:15:17 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

int main() {

	srand(time(0));
	Bureaucrat	st("Stive", 3);
	Bureaucrat	lk("Luke", 30);
	Intern		inr;
	OfficeBlock	ofs;

	std::cout << st << lk;

	try {
		st.increment(5);
		std::cout << "increment Bureaucrat is done !" << std::endl;
	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		ofs.doBureaucracy("nothing", "nothing");
		std::cout << "creating, signing and executing the form is completed !"
		<< std::endl;
	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	ofs.setIntern(&inr);
	ofs.setSigningBureaucrat(&lk);
	ofs.setExecutingBureaucrat(&st);

	try {
		ofs.doBureaucracy("nothing", "tree");
		std::cout << "creating, signing and executing the form is completed !"
		<< std::endl;
	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		ofs.doBureaucracy("shrubbery creation", "tree");
		ofs.doBureaucracy("robotomy request", "robo");
		std::cout << "creating, signing and executing of 2 forms completed !"
		<< std::endl;
	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		ofs.doBureaucracy("presidential pardon", "president");
		std::cout << "creating, signing and executing the form is completed !"
		<< std::endl;
	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}

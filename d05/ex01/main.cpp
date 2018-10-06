/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/13 03:28:19 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	Bureaucrat	st("Stive", 16);
	Bureaucrat	lk("Luke", 20);
	Form		doc("doc", 30, 30);
	Form		imp("important", 5, 5);

	std::cout << st << lk;
	std::cout << doc << imp;

	st.increment(11);
	std::cout << st;

	try {
		st.increment(5);

		std::cout << "Exception's did't work" << std::endl;

	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}
	try {
		lk.decrement(131);

		std::cout << "Exception's did't work" << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	try {

		lk.signForm(doc);
		st.signForm(doc);
		std::cout << doc;

		lk.signForm(imp);
		std::cout << imp;
		st.signForm(imp);
		std::cout << imp;
	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}

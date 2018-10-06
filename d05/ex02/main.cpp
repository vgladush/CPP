/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 15:35:15 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	srand(time(0));
	Bureaucrat	st("Stive", 3);
	Bureaucrat	lk("Luke", 30);
	Form	*	tr = new ShrubberyCreationForm("tree");
	Form	*	rb = new RobotomyRequestForm("robo");
	Form	*	pr = new PresidentialPardonForm("pres");

	std::cout << st << lk;
	std::cout << *tr << *rb << *pr;

	try {

		lk.executeForm(*tr);
		lk.signForm(*tr);
		std::cout << *tr;
		lk.executeForm(*tr);

		st.executeForm(*rb);
		st.signForm(*rb);
		lk.signForm(*rb);
		st.executeForm(*rb);
		lk.executeForm(*rb);

		lk.signForm(*pr);
		st.signForm(*pr);
		lk.executeForm(*pr);
		st.executeForm(*pr);

	} catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	delete tr;
	delete rb;
	delete pr;

	return 0;
}

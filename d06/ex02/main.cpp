/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:29 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:42:26 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"

Base *	generate(void) {
	int i = rand() % 3;

	if (!i)
		return new ClassA();
	if (i == 1)
		return new ClassB();
	return new ClassC();
}

void	identify_from_pointer(Base * p) {
	std::cout << "Identify pointer: ";
	if (dynamic_cast<ClassA*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<ClassB*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<ClassC*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Not found such class" << std::endl;
}

void identify_from_reference( Base & p ) {
	std::cout << "Identify reference: ";
	if (dynamic_cast<ClassA*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<ClassB*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<ClassC*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "not found such class" << std::endl;
}

int		main() {
	srand(time(0));
	Base *bs = generate();

	identify_from_pointer(bs);

	identify_from_reference(*bs);

	delete bs;
	return 0;
}

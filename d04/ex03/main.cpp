/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 22:51:19 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* zaz = new Character("zaz");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	ICharacter* bob = new Character("bob");
	zaz->use(0, *bob);
	zaz->use(1, *bob);

	// test unequip
	std::cout << std::endl;
	ICharacter* Lean = new Character("Lean");

	zaz->use(0, *Lean);
	zaz->use(1, *Lean);

	zaz->unequip(0);
	zaz->unequip(1);

	//should not output anything
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(0, *Lean);
	zaz->use(1, *Lean);

	delete bob;
	delete zaz;
	delete src;
	delete Lean;
	return 0;
}

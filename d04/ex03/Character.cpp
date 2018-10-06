/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 22:30:52 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
	this->mater[0] = 0;
	this->mater[1] = 0;
	this->mater[2] = 0;
	this->mater[3] = 0;
}

Character::Character(Character const & cpy) {
	*this = cpy;
}

void	Character::operator=(Character const & cpy) {
	if (this != &cpy) {
		for (int i = 0; i < 4; ++i) {
			delete this->mater[i];
			this->mater[i] = cpy.mater[i];
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; ++i)
		delete this->mater[i];
}

std::string const & Character::getName() const {
	return this->name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!this->mater[i]) {
			this->mater[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 4) {
		this->mater[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 4 && this->mater[idx]) {
		this->mater[idx]->use(target);
	}
}

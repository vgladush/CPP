/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:36:37 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 19:51:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() {
	this->count = 0;
	this->unit = 0;
}

Squad::~Squad() {
	for (int i = 0; i < this->count; ++i)
		delete this->unit[i];
	delete [] this->unit;
}

Squad::Squad(Squad const & sqd) {
	this->unit = 0;
	this->count = 0;
	*this = sqd;
}

void	Squad::operator=(Squad const & sqd) {
	if (this != &sqd) {
		for (int i = 0; i < this->count; ++i)
			delete this->unit[i];
		delete [] this->unit;
		this->unit = 0;
		this->count = sqd.getCount();
		if (this->count) {
			this->unit = new ISpaceMarine*[this->count];
			for (int i = 0; i < this->count; ++i) {
				this->unit[i] = sqd.getUnit(i);
			}
		}
	}
}

int		Squad::getCount() const {
	return this->count;
}

ISpaceMarine* Squad::getUnit(int nb) const {
	if (nb < this->count)
		return this->unit[nb];
	return 0;
}

int		Squad::push(ISpaceMarine* mar) {
	if (mar && !this->unit) {
		this->unit = new ISpaceMarine*[1];
		this->count = 1;
		this->unit[0] = mar;
	} else if (mar) {
		for (int i = 0; i < this->count; ++i) {
			if (this->unit[i] == mar)
				return this->count;
		}
		ISpaceMarine **tmp = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; ++i)
			tmp[i] = this->unit[i];
		tmp[this->count++] = mar;
		delete [] this->unit;
		this->unit = tmp;
	}
	return this->count;
}

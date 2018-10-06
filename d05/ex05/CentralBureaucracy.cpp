/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:25:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 22:31:27 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() {
	this->burs = 0;
	this->trs = 0;
}

CentralBureaucracy::~CentralBureaucracy() {}

void	CentralBureaucracy::feed(Bureaucrat *bur) {
	if (this->burs == 40) {
		std::cout << "Can not add bureaucracy because this central bureaucracy is full"
		<< std::endl;
		return ;
	}
	if (this->burs % 2) {
		this->ofs[this->burs / 2].setIntern(&this->inr);
		this->ofs[this->burs / 2].setSigningBureaucrat(bur);
	} else
		this->ofs[this->burs / 2].setExecutingBureaucrat(bur);
	this->burs++;
}

void	CentralBureaucracy::queueUp(std::string const &target) {
	if (this->trs == 30) {
		std::cout << "Can not add target because max targets only 30" << std::endl;
		return ;
	}
	this->tgs[this->trs] = target;
	this->trs++;
}

void	CentralBureaucracy::doBureaucracy() {
	std::string	frm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < this->trs; ++i) {
		int rd = rand() % 3;
		int rdof = rand() % 20;
		try {
			this->ofs[rdof].doBureaucracy(frm[rd], this->tgs[i]);
		} catch (std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
	}
}

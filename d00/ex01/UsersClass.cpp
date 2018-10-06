/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsersClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:42:12 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/23 20:06:28 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UsersClass.hpp"

Users::Users(void) {}
Users::~Users(void) {}

void		Users::my_gl(std::string & str)
{
	if (!(std::getline(std::cin, str)))
		exit(0);
}

void		Users::add_user(void)
{
	std::cout << "Enter first name:" << std::endl;
	my_gl(this->fn);
	std::cout << "Enter last name:" << std::endl;
	my_gl(this->ln);
	std::cout << "Enter nickname:" << std::endl;
	my_gl(this->nn);
	std::cout << "Enter login:" << std::endl;
	my_gl(this->lg);
	std::cout << "Enter postal address:" << std::endl;
	my_gl(this->pa);
	std::cout << "Enter email address:" << std::endl;
	my_gl(this->ea);
	std::cout << "Enter phone number:" << std::endl;
	my_gl(this->pn);
	std::cout << "Enter birthday date:" << std::endl;
	my_gl(this->bd);
	std::cout << "Enter favorite meal:" << std::endl;
	my_gl(this->fm);
	std::cout << "Enter underwear color:" << std::endl;
	my_gl(this->uc);
	std::cout << "Enter darkest secret:" << std::endl;
	my_gl(this->ds);
	std::cout << "Contact created" << std::endl;
}

void		Users::vis_users(void)
{
	if (this->fn.size() > 10)
		std::cout << this->fn.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << this->fn;
	std::cout << "|";
	if (this->ln.size() > 10)
		std::cout << this->ln.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << this->ln;
	std::cout << "|";
	if (this->nn.size() > 10)
		std::cout << this->nn.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << this->nn;
	std::cout << "|" << std::endl;
}

void	Users::detal_inf(void)
{
	std::cout << "first name     : " << this->fn << std::endl;
	std::cout << "last name      : " << this->ln << std::endl;
	std::cout << "nickname       : " << this->nn << std::endl;
	std::cout << "login          : " << this->lg << std::endl;
	std::cout << "postal address : " << this->pa << std::endl;
	std::cout << "email address  : " << this->ea << std::endl;
	std::cout << "phone number   : " << this->pn << std::endl;
	std::cout << "birthday date  : " << this->bd << std::endl;
	std::cout << "favorite meal  : " << this->fm << std::endl;
	std::cout << "underwear color: " << this->uc << std::endl;
	std::cout << "darkest secret : " << this->ds << std::endl;
}

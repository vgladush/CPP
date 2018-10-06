/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:50 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/19 14:44:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UsersClass.hpp"

static std::string	toupp(std::string s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] > 96 && s[i] < 123)
			s[i] -= 32;
	}
	return (s);
}

int					main(void)
{
	Users	cont[Users::max];
	int		i = 0;

	while (42)
	{
		std::cout << "Enter command:" << std::endl;
		std::string buf;
		if (!(std::getline(std::cin, buf)))
			return (0);
		buf = toupp(buf);
		if (buf == "ADD")
		{
			if (i > 7)
				std::cout << "phone book is full (max size 8 contacts)" << std::endl;
			else
			{
				cont[i].add_user();
				i++;
			}
		}
		else if (buf == "EXIT")
			return (0);
		else if (buf == "SEARCH")
		{
			std::cout << "+===========================================+" << std::endl;
			std::cout << "|     index|first name| last name|  nickname|" << std::endl;
			for (int j = 0; j < i; j++)
			{
				std::cout << "|         " << j << "|";
				cont[j].vis_users();
			}
			std::cout << "+===========================================+" << std::endl;
			if (i > 0)
			{
				std::cout << "Enter index for detales information:" << std::endl;
				if (!(std::getline(std::cin, buf)))
					return (0);
				if (buf.size() > 1 || buf[0] < 48 || buf[0] > i + 47)
					std::cout << "Wrong index" << std::endl;
				else				
					cont[buf[0] - 48].detal_inf();
			}
		}
		else
			std::cout << "Wrong command" << std::endl;
	}
	return (0);
}

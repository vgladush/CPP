/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:47:07 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 18:47:59 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main()
{
	std::string s = "HI THIS IS BRAIN";

	std::string * pnt = &s;
	std::string & rf = s;

	std::cout << *pnt << std::endl;
	std::cout << rf << std::endl;
}

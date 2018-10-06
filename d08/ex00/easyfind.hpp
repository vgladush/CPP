/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:07:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 16:56:01 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
typename T::const_iterator easyfind(const T &fd, int i)
{
	for (typename T::const_iterator it = fd.begin(); it != fd.end(); ++it) {
		if (*it == i)
			return (it);
	}

	std::ostringstream s;
	s << "Not foun: " << i;
	throw std::out_of_range (s.str());
}

#endif

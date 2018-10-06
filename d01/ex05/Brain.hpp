/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:32:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/03 16:16:11 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN
#define BRAIN

#include <iostream>
#include <sstream>

class Brain
{
public:
	Brain();
	~Brain();

	int	IQ;
	std::string identify() const;
};

#endif

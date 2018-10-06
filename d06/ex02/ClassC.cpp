/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassC.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:07:14 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassC.hpp"

ClassC::ClassC() {}

ClassC::ClassC(ClassC const &cls) {
	(void)cls;
}

void	ClassC::operator=(ClassC const &cls) {
	(void)cls;
}

ClassC::~ClassC() {}

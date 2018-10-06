/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:07:00 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassB.hpp"

ClassB::ClassB() {}

ClassB::ClassB(ClassB const &cls) {
	(void)cls;
}

void	ClassB::operator=(ClassB const &cls) {
	(void)cls;
}

ClassB::~ClassB() {}

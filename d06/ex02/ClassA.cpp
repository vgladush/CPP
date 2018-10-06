/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:06:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassA.hpp"

ClassA::ClassA() {}

ClassA::ClassA(ClassA const &cls) {
	(void)cls;
}

void	ClassA::operator=(ClassA const &cls) {
	(void)cls;
}

ClassA::~ClassA() {}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:03:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_A
#define CLASS_A

#include "Base.hpp"

class ClassA : public Base
{
public:
	ClassA();
	ClassA(ClassA const &cls);
	void	operator=(ClassA const &cls);
	~ClassA();
	
};

#endif

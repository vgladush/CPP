/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:02:34 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_B
#define CLASS_B

#include "Base.hpp"

class ClassB : public Base
{
public:
	ClassB();
	ClassB(ClassB const &cls);
	void	operator=(ClassB const &cls);
	~ClassB();
	
};

#endif

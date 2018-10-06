/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassC.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:55:15 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 12:02:52 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_C
#define CLASS_C

#include "Base.hpp"

class ClassC : public Base
{
public:
	ClassC();
	ClassC(ClassC const &cls);
	void	operator=(ClassC const &cls);
	~ClassC();
	
};

#endif

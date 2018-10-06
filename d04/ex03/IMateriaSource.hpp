/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 21:58:08 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATEIA_SOURE
#define IMATEIA_SOURE

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual	~IMateriaSource() {}
	virtual	void learnMateria(AMateria*) = 0;
	virtual	AMateria* createMateria(std::string const & type) = 0;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/11 21:58:33 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATEIA_SOURE
#define MATEIA_SOURE

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria	*mater[4];
	int			i;

public:
	MateriaSource();
	MateriaSource(MateriaSource const & cpy);
	void	operator=(MateriaSource const & cpy);
	~MateriaSource();
	void	learnMateria(AMateria* mat);
	AMateria* createMateria(std::string const & type);
};

#endif

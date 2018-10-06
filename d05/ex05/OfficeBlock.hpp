/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:01:16 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 18:16:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICE_BLOCK
#define OFFICE_BLOCK

#include "Intern.hpp"

class OfficeBlock
{
	Intern *inr;
	Bureaucrat *sign;
	Bureaucrat *exec;

public:
	struct		NotThreeSpotsException : std::exception {
		char const			*what() const throw();
	};

	OfficeBlock();
	OfficeBlock(Intern *inr, Bureaucrat *sigBur, Bureaucrat *exBur);
	~OfficeBlock();
	void	setIntern(Intern *inr);
	void	setSigningBureaucrat(Bureaucrat *sigBur);
	void	setExecutingBureaucrat(Bureaucrat *exBur);
	void	doBureaucracy(std::string form, std::string target);

};

#endif

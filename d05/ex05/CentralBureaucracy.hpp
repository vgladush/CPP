/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:25:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 22:29:52 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRAL_BUREAUCRACY
#define CENTRAL_BUREAUCRACY

#include "OfficeBlock.hpp"

class CentralBureaucracy
{
	OfficeBlock ofs[20];
	int			burs;
	Intern		inr;
	int			trs;
	std::string	tgs[30];

public:

	CentralBureaucracy();
	~CentralBureaucracy();
	void	feed(Bureaucrat *bur);
	void	queueUp(std::string const &target);
	void	doBureaucracy();
};

#endif

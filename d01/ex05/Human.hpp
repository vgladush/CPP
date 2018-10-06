/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:34:37 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/26 19:26:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN
#define HUMAN

# include "Brain.hpp"

class	Human	{
private:
	const Brain	brain;

public:
	Human();
	~Human ();
	const Brain	&getBrain();
	std::string	identify() const;
};

#endif

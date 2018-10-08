/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:23:26 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
#define STARS_HPP

#include "Constants.hpp"

class Stars
{
public:
	Stars();
	~Stars();
	Stars(Stars & cpy);
	Stars &operator=(Stars & cpy);
	void actStars(WINDOW *win, bool s);

	int x;
	int y;
};

#endif

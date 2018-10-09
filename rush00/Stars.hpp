/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:42:19 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:46:29 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
#define STARS_HPP

class Stars : public Position
{
public:
	Stars();
	~Stars();
	Stars(Stars & cpy);
	Stars &operator=(Stars & cpy);
	void actStars(WINDOW *win, bool s);
};

#endif

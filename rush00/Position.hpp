/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:41:43 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 12:46:18 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_HPP
#define POSITION_HPP

class Position
{

public:
	Position();
	~Position();
	Position(Position & cpy);
	Position &operator=(Position & cpy);
	void actPosition(WINDOW *win, bool s);
	int getX();
	int getY();
	int getA();

	void setX(int);
	void setY(int);
	void setA(int);

protected:
	int _act;
	int _x;
	int _y;
};

#endif
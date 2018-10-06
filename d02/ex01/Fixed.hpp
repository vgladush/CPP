/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:49:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/28 16:37:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed & fix);
	Fixed(const int raw);
	Fixed(const float raw);
	~Fixed();

	void	operator=(const Fixed & fix);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					raw;
	static const int 	bits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &cpy);

#endif

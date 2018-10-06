/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:49:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 19:26:12 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed & fix);
	Fixed(const int raw);
	Fixed(const float raw);
	~Fixed();

	void	operator=(const Fixed & fix);
	bool	operator<(const Fixed & fix) const;
	bool	operator>(const Fixed & fix) const;
	bool	operator<=(const Fixed & fix) const;
	bool	operator>=(const Fixed & fix) const;
	bool	operator==(const Fixed & fix) const;
	bool	operator!=(const Fixed & fix) const;
	Fixed	operator+(const Fixed & fix);
	Fixed	operator-(const Fixed & fix);
	Fixed	operator*(const Fixed & fix);
	Fixed	operator/(const Fixed & fix);
	Fixed	operator++( int ); //pre
	Fixed	operator--( int );
	Fixed	&operator++( void ); //post
	Fixed	&operator--( void );

	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);

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

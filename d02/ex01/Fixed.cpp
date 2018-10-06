/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:49:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/30 20:35:08 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & fix) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(const int val) {
	this->raw = val << this->bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) {
	double x = val * (1 << this->bits);
	int y = x;
	x -= y;
	this->raw = (x * 10 > 4.9 ? y + 1 : y);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(const Fixed & fix) {
	std::cout << "Assignation operator called" << std::endl;
	this->raw = fix.raw;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float	Fixed::toFloat( void ) const {
	return (float)this->raw / (1 << this->bits);
}

int		Fixed::toInt( void ) const {
	return this->raw >> this->bits;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &cpy) {
	o << cpy.toFloat();
	return o;
}

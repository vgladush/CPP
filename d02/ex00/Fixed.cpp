/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:49:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/28 16:45:22 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed & fix) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

void	Fixed::operator=(const Fixed & fix) {
	std::cout << "Assignation operator called" << std::endl;
	this->raw = fix.getRawBits();
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:49:23 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 02:50:02 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : raw(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed & fix) {
	*this = fix;
}

Fixed::Fixed(const int val) {
	this->raw = val << this->bits;
}

Fixed::Fixed(const float val) {
	double x = val * (1 << this->bits);
	int y = x;
	x -= y;
	this->raw = (x * 10 > 4.9 ? y + 1 : y);
}

void	Fixed::operator=(const Fixed & fix) {
	this->raw = fix.raw;
}

int		Fixed::getRawBits( void ) const {
	return this->raw;
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->raw / (1 << this->bits);
}

int		Fixed::toInt( void ) const {
	return this->raw >> this->bits;
}

bool	Fixed::operator<(const Fixed & fix) const {
	return this->raw < fix.raw;
}

bool	Fixed::operator>(const Fixed & fix) const {
	return this->raw > fix.raw;
}

bool	Fixed::operator<=(const Fixed & fix) const {
	return this->raw <= fix.raw;
}

bool	Fixed::operator>=(const Fixed & fix) const {
	return this->raw >= fix.raw;
}

bool	Fixed::operator==(const Fixed & fix) const {
	return this->raw == fix.raw;
}

bool	Fixed::operator!=(const Fixed & fix) const {
	return this->raw != fix.raw;
}

Fixed	Fixed::operator+(const Fixed & fix) {
	return Fixed(this->toFloat() + fix.toFloat());
}

Fixed	Fixed::operator-(const Fixed & fix) {
	return Fixed(this->toFloat() - fix.toFloat());
}

Fixed	Fixed::operator*(const Fixed & fix) {
	return Fixed(this->toFloat() * fix.toFloat());
}

Fixed	Fixed::operator/(const Fixed & fix) {
	return Fixed(this->toFloat() / fix.toFloat());
}

Fixed	Fixed::operator--( int ) {
	Fixed	tmp = *this;
	--*this;
	return tmp;
}

Fixed	Fixed::operator++( int ) {
	Fixed	tmp = *this;
	++*this;
	return tmp;
}

Fixed	&Fixed::operator--( void ) {
	this->raw--;
	return *this;
}

Fixed	&Fixed::operator++( void ) {
	this->raw++;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &cpy) {
	o << cpy.toFloat();
	return o;
}

Fixed			&Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed const		&Fixed::min(Fixed const &a, Fixed const &b) {
	return ((a < b) ? a : b);
}

Fixed			&Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

Fixed const		&Fixed::max(Fixed const &a, Fixed const &b) {
	return ((a > b) ? a : b);
}

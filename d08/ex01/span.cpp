/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:31:10 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 19:31:50 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : n(n) {
	this->ints.reserve(n);
}

Span::Span(Span const &cpy) {
	this->n = 0;
	*this = cpy;
}

void	Span::operator=(Span const &cpy) {
	this->n = cpy.n;
	for (unsigned int i = 0; i < this->n; ++i) {
		this->ints[i] = cpy.ints[i];
	}
}

Span::~Span() {}

void	Span::addNumber(int i) {
	if (this->ints.size() < this->n)
		ints.push_back(i);
	else
		throw std::out_of_range("Сan not add more number, reached a maximum");
}

unsigned int	Span::shortestSpan() {
	if (this->ints.size() < 2)
		throw std::out_of_range("There are not enough numbers to compare");
	unsigned	sh = (this->ints[0] > this->ints[1] ? this->ints[0]
		- this->ints[1] : this->ints[1] - this->ints[0]);
	for (unsigned int i = 0; i < this->ints.size(); ++i) {
		for (unsigned int j = i + 1; j < this->ints.size(); ++j) {
			unsigned min = (this->ints[i] > this->ints[j] ? this->ints[i]
				- this->ints[j] : this->ints[j] - this->ints[i]);
			sh = (min < sh ? min : sh);
		}
	}
	return sh;
}

unsigned int	Span::longestSpan() {
	if (this->ints.size() < 2)
		throw std::out_of_range("There are not enough numbers to compare");
	int	max = this->ints[0];
	int	min = this->ints[0];
	for (unsigned int i = 1; i < this->ints.size(); ++i) {
		if (this->ints[i] > max)
			max = this->ints[i];
		else if (this->ints[i] < min)
			min = this->ints[i];
	}
	return max - min;
}

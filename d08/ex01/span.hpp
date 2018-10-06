/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:31:10 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 19:32:29 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span
{
	unsigned int		n;
	std::vector<int>	ints;

public:
	Span(unsigned int n);
	Span(Span const &cpy);
	~Span();
	void	operator=(Span const &cpy);
	void	addNumber(int i);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	
};

#endif

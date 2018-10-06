/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:44:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 15:38:13 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	unsigned int	sz;
	T	*			arr;

	struct	BeyongArraySizeException : std::exception {
		char const *what() const throw() {
			return "Trying to get beyond the size of an array";
		}
	};

public:
	Array<T>() : arr(0), sz(0) {}
	Array<T>(unsigned int n) {
		arr = new T[n];
		sz = n;
	}

	Array<T>(Array const & cpy) {
		arr = 0;
		*this = cpy;
	}

	void	operator=(Array const & cpy) {
		sz = cpy.sz;
		if (arr)
			delete [] arr;
		if (sz) {
			arr = new T[sz];
			for (unsigned int i = 0; i < sz; ++i)
				arr[i] = cpy.arr[i];
		}
	}
	T		&operator[](unsigned int n) {
		if (n > sz - 1)
			throw BeyongArraySizeException();
		return arr[n];
	}

	~Array() {
		delete [] arr;
	}

	unsigned int	size() {
		return sz;
	}

};

#endif

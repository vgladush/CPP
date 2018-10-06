/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:36:42 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 21:31:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <list>
#include <iterator>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack
{
	std::list<T>	dat;

public:

	typedef typename std::list<T>::iterator iterator;

	MutantStack<T>() {}
	~MutantStack<T>() {}
	MutantStack(MutantStack const &cpy) { *this = cpy; }
	void	operator=(MutantStack const &cpy) {
		if (this != &cpy) {
			if (this->dat.size())
				this->dat.clear();
			this->dat = cpy.dat;
		}
	}

	bool	empty() const { return this->dat.empty(); }

	T const	&top(void) const {
		if (!this->dat.size())
			throw std::out_of_range("Can not \"top\" because this MutantStack is empty");
		return this->dat.front();
	}

	typename std::list<T>::size_type	size() const { return this->dat.size(); }
	
	void	push(T const &value) { this->dat.push_front(value); }
	
	void	pop() {
		if (!this->dat.size())
			throw std::out_of_range("Can not \"pop\" because this MutantStack is empty");
		this->dat.pop_front();
	}

	iterator	begin() { return this->dat.begin(); }
	iterator	end() { return this->dat.end(); }

	operator	std::stack<T>() {
		std::stack<T> 	stack;
		for (iterator end = this->end(); end != this->begin(); --end) {
			stack.push(*end);
		}
		return stack;
	}

};

#endif

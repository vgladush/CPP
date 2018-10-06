/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:51:22 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 14:36:34 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void	incBegEnd(T const & c) {
	std::cout << 'b' + c + 'e' << " ";
}

template <typename T>
void	printT(T const & c) {
	std::cout << c << " ";
}

template <typename T, class V>
void	iter(T *arr, size_t sz, V *fun) {
	for (size_t i = 0; i < sz; ++i)
		fun(arr[i]);
}

int		main() {
	int i[4] = {23, 23523, 16, 547};
	std::string	s[3] = {"Hello", "World", "!"};

	iter(i, 4, &printT<int>);
	std::cout << std::endl;
	iter(s, 3, &printT<std::string>);
	std::cout << std::endl;

	iter(i, 4, &incBegEnd<int>);
	std::cout << std::endl;
	iter(s, 3, &incBegEnd<std::string>);
	std::cout << std::endl;

	return 0;
}

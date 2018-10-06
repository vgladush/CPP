/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:50:53 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/16 13:49:14 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void	swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	const &min(T const &a, T const &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
T	const &max(T const &a, T const &b) {
	if (a > b)
		return a;
	return b;
}

int	main()
{
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	}
	std::cout << std::endl;
	{
		float	a = 21.42f;
		float	b = 42.21f;
		std::cout << "Before swap a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "After swap a = " << a << ", b = " << b << std::endl;

		std::cout << "Max value: " << max(a, b) << std::endl
		<< "Min value: " << min(a, b) << std::endl;

		char	c = 'a';
		char	d = 'z';
		std::cout << "Before swap c = " << c << ", d = " << d << std::endl;
		swap(c, d);
		std::cout << "After swap d = " << c << ", d = " << d << std::endl;

		std::cout << "Max value: " << max(c, d) << std::endl
		<< "Min value: " << min(c, d) << std::endl;
	}
	return 0;
}

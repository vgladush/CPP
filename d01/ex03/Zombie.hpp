/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:38:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/03 16:12:42 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <ctime>

class Zombie
{

public:
	Zombie(std::string name = "Zombie", std::string type = "Alive");
	~Zombie();

	void	announce();
	std::string name;

private:
	std::string type;

} ;

#endif

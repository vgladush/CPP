/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsersClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:33:37 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/23 20:08:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERSCLASS_HPP
#define USERSCLASS_HPP

# include <iostream>
# include <iomanip>

class Users
{
	public:
		static const int max = 8;
		std::string fn;
		std::string ln;
		std::string nn;
		std::string lg;
		std::string pa;
		std::string ea;
		std::string pn;
		std::string bd;
		std::string fm;
		std::string uc;
		std::string ds;
		
	Users(void);
	~Users(void);

	void		add_user(void);
	void		vis_users(void);
	void		detal_inf(void);
	void		my_gl(std::string & str);

};

#endif

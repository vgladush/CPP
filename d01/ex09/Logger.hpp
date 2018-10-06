/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:54:10 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/27 22:46:51 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <ctime>

class Logger
{
public:
	Logger(std::string file_name = "test.txt");
	void		log(std::string const & dest, std::string const & message);

private:
	std::string fname;
	void		logToConsole(std::string const & s);
	void		logToFile(std::string const & s);
	std::string	makeLogEntry(std::string const & s);
};

#endif

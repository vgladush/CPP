/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:54:10 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/27 22:49:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string file_name) : fname(file_name) {}

void		Logger::logToConsole(std::string const & s) {
	std::cout << s << std::endl;
}

void		Logger::logToFile(std::string const & s) {
	std::ofstream	fnm((this->fname).c_str());
	fnm << s << std::endl;
	fnm.close();
}

std::string	Logger::makeLogEntry(std::string const & s) {
	std::time_t t = std::time(0);
	std::tm	*now = std::localtime(&t);
	char buffer [24];
	strftime (buffer, 24, "[%x %X]", now);
	return buffer + s;
}

void		Logger::log(std::string const & dest, std::string const & message) {
	typedef void (Logger::*Func)(std::string const &);
	Func fun[2] = {&Logger::logToConsole, &Logger::logToFile};
	std::string	varis[2] = {"logToConsole", "logToFile"};
	for (int i = 0; i < 2; ++i) {
		if (dest == varis[i]) {
			(this->*fun[i])(makeLogEntry(message));
			break ;
		}
	}
}

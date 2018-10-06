/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:54:10 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/27 21:43:52 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main()
{
	Logger lg;
	lg.log("logToConsole", "test write to console");
	lg.log("logToFile", "test write to file");
	return 0;
}

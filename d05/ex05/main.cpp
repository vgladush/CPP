/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:01:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/15 22:32:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

int main() {

	srand(time(0));

	CentralBureaucracy	centr;
	Bureaucrat			bur1("John", 50);
	Bureaucrat			bur2("Rick", 110);
	Bureaucrat			bur3("Sarah", 78);
	Bureaucrat			bur4("David", 4);
	Bureaucrat			bur5("Robert", 2);
	Bureaucrat			bur6("Kristen", 5);


	centr.feed(&bur1);
	centr.feed(&bur2);
	centr.feed(&bur3);
	centr.feed(&bur4);
	centr.feed(&bur5);
	centr.feed(&bur6);
	centr.feed(&bur1);
	centr.feed(&bur2);
	centr.feed(&bur3);
	centr.feed(&bur4);
	centr.feed(&bur5);
	centr.feed(&bur6);
	centr.feed(&bur1);
	centr.feed(&bur2);
	centr.feed(&bur3);
	centr.feed(&bur4);
	centr.feed(&bur5);
	centr.feed(&bur6);
	centr.feed(&bur3);
	centr.feed(&bur5);

	centr.queueUp("Haha");
	centr.queueUp("Nice");
	centr.queueUp("Cool");
	centr.queueUp("Dich");
	centr.queueUp("Norm");
	centr.queueUp("Pazl");
	centr.queueUp("Rich");
	centr.queueUp("Just");
	centr.queueUp("Snow");
	centr.queueUp("Portal");
	centr.queueUp("Dock");
	centr.queueUp("Katana");
	centr.queueUp("Ship");
	centr.queueUp("Star");
	centr.queueUp("Gues");
	centr.queueUp("Act");
	centr.queueUp("City");
	centr.queueUp("Build");
	centr.queueUp("Zaraza");
	centr.queueUp("Buhlo");
	centr.queueUp("Eat");
	centr.queueUp("Water");
	centr.queueUp("Meat");
	centr.queueUp("Idea");
	centr.queueUp("Mud");
	centr.queueUp("Good");
	centr.queueUp("Bad");
	centr.queueUp("Look");
	centr.queueUp("Listen");
	centr.queueUp("Finaly");

	centr.queueUp("Nothing");

	centr.doBureaucracy();
	return 0;
}

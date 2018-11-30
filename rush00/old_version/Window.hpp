/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:23:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Constants.hpp"

class Window {

public:

	Window(void);
	Window(Window const &);
	~Window(void);
	Window const &operator=(Window const &);

	void	start(void);
	void	newStart(void);
	void	accident(void);
	void	reloadGun(void);
	void	checkCrash(void);
	void	clearBeggin(void);
	void	enemyAttack(void);
	void	my_clear(void);
	void	set_mus(bool t);
	int		game_pause(void);

	Asteroids	asteroid[ASTEROIDS];
	Enemy		enemy[ENEMIES];
	Stars		stars[STARS];
	Ship		Ship;

	void	Inform(void);
	void	bulletsBoss(void);

	Bullet enemyBullets[MAX_BULLETS];

private:

	int		height;
	int		width;
	int		speed;
	int 	level;
	int		score;
	int		totalScore;
	int		health;
	bool	mus;
	bool	lvlup;
	size_t	time;

	WINDOW * win;
	WINDOW * infa;
	WINDOW * frame;
};

#endif

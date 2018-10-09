/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:45:32 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 14:10:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#define WIDTH 200
#define HEIGHT 50
#define BULLETS 16

#define SCORE_HEIGHT 10
#define STARS 70
#define ASTEROIDS 20

#define SPEED 10000
#define SCORE_TO_BOSS 20
#define MAX_BULLETS 16
#define BOSS_HP 10
#define ENEMIES 5
#define FINAL 5

#include "unistd.h"
#include <iostream>
#include <fstream>
#include <ncurses.h>

#include "Position.hpp"
#include "Enemy.hpp"
#include "Stars.hpp"
#include "Asteroids.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"

class Game 
{

	public:

	Game(void);
	Game(Game const &);
	~Game(void);
	Game const &operator=(Game const &);

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

	//////getters
	int 	getHeight();
	int 	getWidth();
	int 	getSpeed();
	int 	getLevel();
	int 	getScore();
	int 	getTotalScore();
	int 	getHealth();
	bool 	getMus();
	bool 	getLevelUp();
	size_t 	getTime();

	Asteroids	asteroid[ASTEROIDS];
	Enemy		enemy[ENEMIES];
	Stars		stars[STARS];
	Ship		Ship;

	void	Inform(void);
	void	bulletsBoss(void);

	Bullet enemyBullets[MAX_BULLETS];

	private:

	WINDOW * _win;
	int		_height;
	int		_width;
	int		_speed;
	int 	_level;
	int		_score;
	int		_totalScore;
	int		_health;
	bool	_mus;
	bool	_lvlup;
	size_t	_time;

	
};

#endif

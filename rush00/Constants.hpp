/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Constants.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/08/08 18:21:53 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_INCLUDES
#define CONSTANTS_INCLUDES

#define WIDTH 200
#define HEIGHT 50
#define SCORE_HEIGHT 10
#define STARS 70
#define ASTEROIDS 20
#define BULLETS 16
#define SPEED 10000
#define SCORE_TO_BOSS 20
#define MAX_BULLETS 16
#define BOSS_HP 10
#define ENEMIES 5
#define FINAL 5

#include "unistd.h"
#include <iostream>
#include <ncurses.h>

#include "Stars.hpp"
#include "Asteroids.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Enemy.hpp"

#endif

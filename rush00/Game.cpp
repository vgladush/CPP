/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:45:20 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/07 14:37:07 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() 
{
	srand(time(0));
	this->_health = 0;
	this->_height = HEIGHT;
	this->_width = WIDTH;
	this->newStart();
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, true);
	this->_win = newwin(HEIGHT + 10, WIDTH - 1, 0, 0);
	keypad(this->_win, true);
	nodelay(this->_win, true);
	wrefresh(this->_win);
	refresh();
	return;
}

Game::Game(Game const & src) 
{
	*this = src;
	return;
}

Game::~Game() 
{
	delwin(this->_win);
	if (this->_mus)
		system("killall afplay");
	endwin();
}

Game const &	Game::operator = (Game const & rhs) 
{
	return rhs;
}

void	Game::Inform() 
{
	if (this->_health > 0 && !this->_lvlup) 
	{
		mvwprintw(this->_win, 1 + HEIGHT, WIDTH / 2 - 6, "INFORMATION:");
		mvwprintw(this->_win, 3 + HEIGHT, 5, "Level: %d", this->_level);
		mvwprintw(this->_win, 5 + HEIGHT, 5, "Score: %d", this->_totalScore);
		wattron(this->_win, COLOR_PAIR(2));
		mvwprintw(this->_win, 3 + HEIGHT, 65, "Lives: %d", this->_health);
		wattroff(this->_win, COLOR_PAIR(2));
		mvwprintw(this->_win, 3 + HEIGHT, 35, "Time: %d", this->_time);
		mvwprintw(this->_win, 5 + HEIGHT, 35, "Speed: %d", this->_speed);
		mvwprintw(this->_win, 3 + HEIGHT, 145, "Overheat:");
		int red = 0;
		for (int i = 0; i < BULLETS; ++i)
			if (this->Ship.bullets[i].act)
				red++;
		wattron(this->_win, COLOR_PAIR(1));
		for (int i = 0; i < red; ++i)
			mvwaddch(this->_win, 5 + HEIGHT, 135 + i * 2, '!');
		wattroff(this->_win, COLOR_PAIR(1));
		wattron(this->_win, COLOR_PAIR(3));
		for (int i = 0; i < BULLETS - red; ++i)
			mvwaddch(this->_win, 5 + HEIGHT, 135 + (red + i) * 2, '!');
		wattroff(this->_win, COLOR_PAIR(3));
		if (!red)
			this->Ship.hot = false;
		if (this->Ship.hot) 
		{
			wattron(this->_win, COLOR_PAIR(1));
			mvwprintw(this->_win, 3 + HEIGHT, 95, "YOUR WEAPON IS VERY HOT ! ! !");
			wattroff(this->_win, COLOR_PAIR(1));
			wattron(this->_win, COLOR_PAIR(2));
			if (red < BULLETS)
				mvwprintw(this->_win, 5 + HEIGHT, 95, "PRESS 'R' TO COOLDOWN ! ! ! !");
			wattroff(this->_win, COLOR_PAIR(2));
		}
		wattron(this->_win, COLOR_PAIR(1));
		if (this->enemy[0].getA())
			mvwprintw(this->_win, 5 + HEIGHT, 65, "Boss HP: %d", this->enemy[0].hp);
		wattroff(this->_win, COLOR_PAIR(1));
	} 
	else if (this->_lvlup) 
	{
		wattron(this->_win, COLOR_PAIR(3));
		mvwprintw(this->_win, 24, 97, "Detail:");
		mvwprintw(this->_win, 26, 78, "Lives: %d",  this->_health);
		mvwprintw(this->_win, 26, 111, "Score: %d", this->_totalScore);
		mvwprintw(this->_win, 28, 78, "Time: %d", this->_time);
		mvwprintw(this->_win, 28, 111, "Speed: %d", this->_speed);
		wattroff(this->_win, COLOR_PAIR(3));
		wattron(this->_win, COLOR_PAIR(2));
		if (this->_level < FINAL) 
		{
			mvwprintw(this->_win, 5 + HEIGHT, WIDTH / 2 - 6, "Next leve: %d", this->_level + 1);
			mvwprintw(this->_win, 3 + HEIGHT, WIDTH / 2 - 16, "You got extra life for the boss!");
			mvwprintw(this->_win, 18, WIDTH / 2 - 18, "Congratulations, you passed level: %d", this->_level);
			mvwprintw(this->_win, 21, WIDTH / 2 - 12, "Press \"F\" to continue.");
		} else 
		{
			mvwprintw(this->_win, 3 + HEIGHT, WIDTH / 2 - 7, "YOU WON ! ! !");
			mvwprintw(this->_win, 18, WIDTH / 2 - 13, "Congratulations, you won!");
			mvwprintw(this->_win, 21, WIDTH / 2 - 12, "Press \"F\" for new game.");
		}
		wattroff(this->_win, COLOR_PAIR(2));
	} else 
	{
		wattron(this->_win, COLOR_PAIR(1));
		mvwprintw(this->_win, 3 + HEIGHT, WIDTH / 2 - 7, "You lose ! ! !");
		mvwprintw(this->_win, 18, WIDTH / 2 - 5, "Game Over!");
		wattroff(this->_win, COLOR_PAIR(1));
		wattron(this->_win, COLOR_PAIR(2));
		mvwprintw(this->_win, 21, WIDTH / 2 - 12, "Press \"F\" for new game.");
		wattroff(this->_win, COLOR_PAIR(2));
		wattron(this->_win, COLOR_PAIR(3));
		mvwprintw(this->_win, 24, 95, "Last game:");
		mvwprintw(this->_win, 26, 78, "Level: %d", this->_level);
		mvwprintw(this->_win, 26, 111, "Score: %d", this->_totalScore);
		mvwprintw(this->_win, 28, 78, "Time: %d", this->_time);
		mvwprintw(this->_win, 28, 111, "Speed: %d", this->_speed);
		wattroff(this->_win, COLOR_PAIR(3));
	}
	mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3, "Press:");
	mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 10, (this->_lvlup ? "f - continue" : "p - to pause"));
	mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 27, "m - to turn on/off the sound");
	if (this->_mus) 
	{
		wattron(this->_win, COLOR_PAIR(2));
		mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 50, "sound");
		wattroff(this->_win, COLOR_PAIR(2));
	}
	mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 60, "ESC - to exit");
	return;
}

void	Game::my_clear() 
{
	for (int i = 0; i < HEIGHT; ++i) 
	{
		for (int j = 0; j < WIDTH; ++j) 
		{
			mvwaddch(this->_win, i, j, ' ');
		}
	}
	for (int i = 0; i < SCORE_HEIGHT; ++i) 
	{
		for (int j = 0; j < WIDTH; ++j) 
		{
			mvwaddch(this->_win, i + HEIGHT, j, ' ');
		}
	}
	return;
}

void	Game::set_mus(bool t) 
{
	 std::ifstream file;
   	if (this->_mus)
		system("killall afplay");
	if (t)
		this->_mus = (this->_mus ? false : true);
	mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 50, "sound");
	if (this->_mus) 
	{
		wattron(this->_win, COLOR_PAIR(2));
		mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 50, "sound");
		wattroff(this->_win, COLOR_PAIR(2));
		if (!this->_health)
		{
			file.open("./sounds/loose.mp3");
			if (file)
				system("afplay ./sounds/loose.mp3 -v 0.3 &");
		}
		else if (this->_level == FINAL && this->_lvlup)
		{
			file.open("./sounds/fin.mp3");
			if (file)
				system("afplay ./sounds/fin.mp3 &");
		}
		else if (this->_lvlup)
		{
			file.open("./sounds/menu.mp3");
			if (file)
				system("afplay ./sounds/menu.mp3 &");
		}
		else if (this->_level == FINAL && this->enemy[0].getA())
		{
			file.open("./sounds/finboss.mp3");
			if (file)
				system("afplay ./sounds/finboss.mp3 &");
		}
		else if (this->_level == FINAL && !this->enemy[0].getA())
		{
			file.open("./sounds/finlvl.mp3");
			if (file)
				system("afplay ./sounds/finlvl.mp3 &");
		}
		else if (this->enemy[0].getA())
		{
			file.open("./sounds/boss.mp3");
			if (file)
				system("afplay ./sounds/boss.mp3 -v 0.3 &");
		}
		else if (this->_level == 1)
		{
			file.open("./sounds/start.mp3");
			if (file)
				system("afplay ./sounds/start.mp3 &");
		}
		else 
		{
			file.open("./sounds/lvl.mp3");
			if (file)
				system("afplay ./sounds/lvl.mp3 &");
		}
	}
	wrefresh(this->_win);
	return;
}

int		Game::game_pause() 
{
	wattron(this->_win, COLOR_PAIR(2));
	mvwprintw(this->_win, 7 + HEIGHT, WIDTH / 3 + 17, "pause");
	wattroff(this->_win, COLOR_PAIR(2));
	wattron(this->_win, COLOR_PAIR(6));
	mvwprintw(this->_win, HEIGHT / 2 - 1, WIDTH / 2 - 3, "PAUSE");
	mvwprintw(this->_win, HEIGHT / 2 + 1, WIDTH / 2 - 15, "Press 'p' or spase to continue");
	wattroff(this->_win, COLOR_PAIR(6));
	wrefresh(this->_win);
	int key = 0;
	wrefresh(this->_win);
	while (key != 'p' && key != ' ') 
	{
		key = std::tolower(wgetch(this->_win));
		if (key == 27)
			return 1;
		else if (key == 'm')
			set_mus(true);
	}
	return 0;
}

void	Game::start() 
{
	std::ifstream file;
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	wclear(this->_win);
	file.open("./sounds/start.mp3");
	if (file)
		system("afplay ./sounds/start.mp3 &");
	this->_mus = true;
	while (1) 
	{

		int key = std::tolower(wgetch(this->_win));
		if (key == KEY_UP || key == 'w')
			this->Ship.moveShip(1);
		else if (key == KEY_DOWN || key == 's')
			this->Ship.moveShip(2);
		else if (key == KEY_LEFT || key == 'a')
			this->Ship.moveShip(3);
		else if (key == KEY_RIGHT || key == 'd')
			this->Ship.moveShip(0);
		else if (key == 'r') 
		{
			if (this->Ship.hot)
				this->reloadGun();
		}
		else if (key == ' ') 
		{
			if (!this->Ship.hot)
			{
				if (this->_mus && this->_health)
				{
					file.open("./sounds/shot.mp3");
					if (file)
					{
						system("afplay ./sounds/shot.mp3 -v 0.3 &");
					}
					file.close();
					
				}
				this->Ship.createBullet();
			}
		}
		else if (key == 27)
			break ;
		else if (key == '+')
			(this->_speed > 249) && (this->_speed -= 250);
		else if (key == '-')
			(this->_speed < 24000) && (this->_speed += 250);
		else if (key == 'f')
			this->newStart();
		else if (key == 'p') 
		{
			if (!this->_lvlup && this->_health && this->game_pause())
				return;
		}
		else if (key == 'm')
			set_mus(true);
		
		if (this->_health && !this->_lvlup) 
		{
			my_clear();
			wattron(this->_win, COLOR_PAIR(4));
			for (int i = 0; i < STARS; i++)
				stars[i].actStars(this->_win, !(this->_time % 5));
			wattroff(this->_win, COLOR_PAIR(4));
			if (this->enemy[0].getA() < 2) 
			{
				wattron(this->_win, COLOR_PAIR(6));
				for (int i = 1; i < ASTEROIDS; i++)
					this->asteroid[i].actAsteroids(this->_win, !(this->_time % 3), this->enemy[0].getA());
				wattroff(this->_win, COLOR_PAIR(6));
				wattron(this->_win, COLOR_PAIR(1));
				this->enemyAttack();
				wattroff(this->_win, COLOR_PAIR(1));
				if (!this->enemy[0].getA())
					this->accident();
			}
			clearBeggin();

			wattron(this->_win, COLOR_PAIR(2));
			this->Ship.actShip(this->_win);
			wattroff(this->_win, COLOR_PAIR(2));
			if (!this->enemy[0].getA() && this->_score >= SCORE_TO_BOSS * this->_level) 
			{
				this->enemy[0].setA(1);
				this->set_mus(false);
				for (int i = 0; i < ASTEROIDS; ++i) 
				{
					if (this->asteroid[i].getA() == 1)
						this->asteroid[i].setA(2);
				}
				for (int i = 1; i < ENEMIES; ++i) 
				{
					if (this->enemy[i].getA() == 1)
						this->enemy[i].setA(2);
				}
				for (int i = 0; i < MAX_BULLETS; ++i)
					this->enemyBullets[i].act = false;
			}
			if (this->enemy[0].getA()) 
			{
				wattron(this->_win, COLOR_PAIR(1));
				this->enemy[0].printBoss(this->_win);
				if (this->enemy[0].getA() < 3) 
				{
					if (!(this->_time % 6))
						this->enemy[0].moveBoss();
					this->bulletsBoss();
					checkCrash();
				}
				wattroff(this->_win, COLOR_PAIR(1));
				if (!(this->_time % 42) && this->enemy[0].getA() > 2) 
				{
					this->enemy[0].setA(this->enemy[0].getA() + 1);
					if (this->enemy[0].getA() - 1 > 5)
					{
						this->enemy[0].setA(this->enemy[0].getA() + 1);
						this->_lvlup = true;
					}
				}
			}
			if (this->_lvlup || !this->_health) 
			{
				wclear(this->_win);
				set_mus(false);
			}

			this->_time++;

			Inform();
			box(this->_win, 0, 0);
			for (int i = 1; i < WIDTH - 2; ++i)
			{
				mvwaddch(this->_win, HEIGHT - 1, i, '=');
				mvwaddch(this->_win, HEIGHT, i, '=');
			}
			wrefresh(this->_win);
		}

		usleep(this->_speed);
	}
	return;
}

void	Game::newStart() 
{
	if (this->_lvlup && this->_level == FINAL)
		this->_health = 0;
	if (this->_health < 1) 
	{
		this->_level = 0;
		this->_totalScore = 0;
		this->_health = 2;
		this->_lvlup = true;
		this->_time = 0;
		this->Ship.setX(3);
		this->Ship.setY(24);
	}
	if (this->_lvlup) 
	{
		this->_score = 0;
		this->_speed = (SPEED - this->_level * 900 < 1 ? 0 : SPEED - this->_level * 900);
		this->_totalScore += this->_level * 100;
		this->_health++;
		this->_level++;
		this->enemy[0].hp = BOSS_HP * this->_level;
		this->enemy[0].setY(HEIGHT / 2 - 5);
		this->enemy[0].setX(WIDTH);
		this->enemy[0].setA(0);
		this->_lvlup = false;
		this->set_mus(false);
		for (int i = 0; i < ASTEROIDS; ++i)
			this->asteroid[i].setA(0);
		for (int i = 0; i < BULLETS; ++i)
			this->Ship.bullets[i].act = false;
		for (int i = 1; i < ENEMIES; ++i) 
		{
			this->enemy[i].setX(1 + (rand() % WIDTH - 2));
			this->enemy[i].setY(1 + rand() % (HEIGHT - 2));
			this->enemy[i].hp = 2;
			this->enemy[i].setA(0);
		}
		for (int i = 0; i < MAX_BULLETS; ++i)
			this->enemyBullets[i].act = false;
	}
}

void	Game::reloadGun() 
{
	for (int i = 0; i < BULLETS; i++) 
	{
		if (!this->Ship.bullets[i].act) 
		{
			this->Ship.hot = false;
			return ;
		}
	}
}

void	Game::checkCrash() 
{
	for (int i = 0; i < BULLETS; ++i) 
	{
		if (this->Ship.bullets[i].act && this->Ship.bullets[i].x < this->enemy[0].getX() + 4
			&& ((this->Ship.bullets[i].x > this->enemy[0].getX() - 6 && this->Ship.bullets[i].y
			> this->enemy[0].getY() + 2 && this->Ship.bullets[i].y < this->enemy[0].getY() + 6) ||
			(this->Ship.bullets[i].x > this->enemy[0].getX() - 4 && this->Ship.bullets[i].y
			> this->enemy[0].getY() - 1 && this->Ship.bullets[i].y < this->enemy[0].getY() + 9))) 
		{
			this->Ship.bullets[i].act = false;
			this->enemy[0].hp--;
			if (this->enemy[0].hp < 1)
				this->enemy[0].setA(3);
		}
		for (int j = 0; j < MAX_BULLETS; ++j) 
		{
			if (this->enemyBullets[j].act && this->Ship.bullets[i].act && 
				this->Ship.bullets[i].y == enemyBullets[j].y && this->Ship.bullets[i].x > this->enemyBullets[j].x) 
			{
				this->enemyBullets[j].act = false;
				this->Ship.bullets[i].act = false;
				mvwprintw(this->_win, this->Ship.bullets[i].y - 1, this->Ship.bullets[i].x - 1, "\\  /");
				mvwprintw(this->_win, this->Ship.bullets[i].y + 1, this->Ship.bullets[i].x - 1, "/  \\");
			}
		}
	}
	return;
}

void	Game::accident() 
{
	for (int i = 0; i < BULLETS; ++i) 
	{
		for (int j = 0; j < ASTEROIDS; ++j) 
		{
			if (this->asteroid[j].getA() == 1 && this->Ship.bullets[i].act &&
				this->Ship.bullets[i].y > this->asteroid[j].getY() - 2 && this->Ship.bullets[i].y
				< this->asteroid[j].getY() + 2 && this->Ship.bullets[i].x < this->asteroid[j].getX()
				+ 3 && this->Ship.bullets[i].x > this->asteroid[j].getX() - 1) 
			{
				this->asteroid[j].setA(2);
				this->Ship.bullets[i].act = false;
				this->_score++;
				this->_totalScore++;
			}
		}
		for (int j = 0; j < MAX_BULLETS; ++j) 
		{
			if (this->enemyBullets[j].act && this->Ship.bullets[i].act && 
				this->Ship.bullets[i].y == enemyBullets[j].y && this->Ship.bullets[i].x > this->enemyBullets[j].x) 
			{
				this->enemyBullets[j].act = false;
				this->Ship.bullets[i].act = false;
				mvwprintw(this->_win, this->Ship.bullets[i].y - 1, this->Ship.bullets[i].x - 1, "\\  /");
				mvwprintw(this->_win, this->Ship.bullets[i].y + 1, this->Ship.bullets[i].x - 1, "/  \\");
			}
		}
		for (int j = 0; j < ENEMIES; ++j) 
		{
			if (this->enemy[j].getA() == 1 && this->Ship.bullets[i].y == enemy[j].getY() &&
				this->Ship.bullets[i].x > enemy[j].getX() && this->Ship.bullets[i].x < enemy[j].getX() + 4) 
			{
				if (!(--this->enemy[j].hp))
					this->enemy[j].setA(2);
					this->_score += 5;
					this->_totalScore += 5;
					this->Ship.bullets[i].act = false;					
			}
		}
	}
	for (int i = 0; i < ASTEROIDS; ++i) 
	{
		if (this->asteroid[i].getA() == 1 && this->Ship.getY() > this->asteroid[i].getY() - 3
			&& this->Ship.getY() < this->asteroid[i].getY() + 3 && this->Ship.getX() <
			this->asteroid[i].getX() + 3 && this->Ship.getX() > this->asteroid[i].getX() - 3) 
		{
			this->_health--;
			this->asteroid[i].setA(2);
		}
	}
	return;
}

void	Game::bulletsBoss() 
{
	for (int i = 0; i < MAX_BULLETS; i++) 
	{
		if (this->enemyBullets[i].act) 
		{
			mvwprintw(this->_win, this->enemyBullets[i].y, this->enemyBullets[i].x, "<<");
			if (this->enemyBullets[i].y < this->Ship.getY() + 2 && this->enemyBullets[i].y >
				this->Ship.getY() - 2 && this->enemyBullets[i].x > this->Ship.getX() - 1 &&
				this->enemyBullets[i].x < this->Ship.getX() + 3) 
			{
				this->_health--;
				this->enemyBullets[i].act = false;
			}
		}
		if (!this->enemyBullets[i].x--)
			this->enemyBullets[i].act = false;
	}
	if (!(this->_time % 9)) 
	{
		int i = MAX_BULLETS / 2;
		int r = (this->enemyBullets[i - 1].x < 1 ? 0 : i - 1);
		if (r && this->enemyBullets[0].x > 60)
			return ;
		while (i--) {
			if (!this->enemyBullets[r].act) 
			{
				this->enemyBullets[r].act = true;
				this->enemyBullets[r].x = this->enemy[0].getX() - 6;
				this->enemyBullets[r].y = this->enemy[0].getY() + 4;
				return ;
			}
			r++;
		}
	}
	return;
}

void	Game::clearBeggin(void) 
{
	for (int i = 0; i < ASTEROIDS; ++i) 
	{

		if (this->asteroid[i].getA() && this->asteroid[i].getX() > WIDTH - 5) 
		{
			for (int j = 0; this->asteroid[i].getX() - j > WIDTH - 5; ++j) 
			{
				mvwaddch(this->_win, this->asteroid[i].getY() + 1, j, ' ');
				mvwaddch(this->_win, this->asteroid[i].getY() + 2, j, ' ');
				mvwaddch(this->_win, this->asteroid[i].getY() + 3, j, ' ');
				mvwaddch(this->_win, this->asteroid[i].getY(), j, ' ');
				mvwaddch(this->_win, this->asteroid[i].getY() - 1, j, ' ');
			}
		}
	}
	return;
}

void	Game::enemyAttack() 
{
	for (int i = 1; i < ENEMIES; ++i) 
	{
		this->enemy[i].actEnemy(this->_win, this->_time);
		if (this->enemy[i].getA() == 1) 
		{
			int b = i * 2;
			if (this->Ship.getY() > this->enemy[i].getY() - 2	&& this->Ship.getY() <
				this->enemy[i].getY() + 2 && this->Ship.getX() < this->enemy[i].getX() + 3
				&& this->Ship.getX() > this->enemy[i].getX() - 3) 
			{
				this->_health--;
				this->enemy[i].setA(2);
			} 
			else if (!this->enemyBullets[b].act && !this->enemyBullets[b + 1].act &&
				this->enemyBullets[b + 1].x < enemy[i].getX() - 120) 
			{
				this->enemyBullets[b].act = true;
				this->enemyBullets[b].x = enemy[i].getX() - 1;
				this->enemyBullets[b].y = enemy[i].getY();
			} 
			else if (!this->enemyBullets[b + 1].act && this->enemyBullets[b].x < enemy[i].getX() - 30) 
			{
				this->enemyBullets[b + 1].act = true;
				this->enemyBullets[b + 1].x = enemy[i].getX() - 1;
				this->enemyBullets[b + 1].y = enemy[i].getY();
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++) 
	{
		if (this->enemyBullets[i].act) 
		{
			mvwprintw(this->_win, this->enemyBullets[i].y, this->enemyBullets[i].x, "<-");
			if (this->enemyBullets[i].y < this->Ship.getY() + 2 && this->enemyBullets[i].y >
				this->Ship.getY() - 2 && this->enemyBullets[i].x > this->Ship.getX() - 1 &&
				this->enemyBullets[i].x < this->Ship.getX() + 3) 
			{
				this->_health--;
				this->enemyBullets[i].act = false;
			}
			if (!this->enemyBullets[i].x--)
				this->enemyBullets[i].act = false;
		}
	}
	return;
}
///////////////////////geters
	int Game::getHeight() 
	{
		return(this->_height);
	}
	int Game::getWidth() 
	{
		return(this->_width);
	}
	int Game::getSpeed() 
	{
		return (this->_speed);
	}
	int Game::getLevel() 
	{
		return (this->_level);
	}
	int Game::getScore() 
	{
		return(this->_score);
	}
	int Game::getTotalScore() 
	{
		return (this->_totalScore);
	}
	int Game::getHealth() 
	{
		return (this->_health);
	}
	bool Game::getMus() 
	{
		return (this->_mus);
	}
	bool Game::getLevelUp() 
	{
		return (this->_lvlup);
	}
	size_t Game::getTime() 
	{
		return (this->_time);
	}

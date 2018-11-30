/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:49:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/10/04 14:46:15 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window() {
	this->health = 0;
	this->height = HEIGHT;
	this->width = WIDTH;
	this->newStart();
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, true);

	this->frame = newwin(HEIGHT + 12, WIDTH + 3, 0, 0);
	this->win = newwin(HEIGHT - 1, WIDTH - 1, 1, 2);
	keypad(this->win, true);
	nodelay(this->win, true);
	wrefresh(this->win);
	this->infa = newwin(SCORE_HEIGHT, WIDTH - 1, HEIGHT + 1, 2);
	nodelay(this->infa, true);
	refresh();
}

Window::Window(Window const & src) {
	*this = src;
}

Window::~Window() {
	delwin(this->win);
	delwin(this->infa);
	delwin(this->frame);
	if (this->mus)
		system("killall afplay");
	endwin();
}

Window const &	Window::operator = (Window const & rhs) {
	return rhs;
}

void	Window::Inform() {
	if (this->health > 0 && !this->lvlup) {
		mvwprintw(this->infa, 1, WIDTH / 2 - 6, "INFORMATION:");
		mvwprintw(this->infa, 3, 5, "Level: %d", this->level);
		mvwprintw(this->infa, 5, 5, "Score: %d", this->totalScore);
		wattron(this->infa, COLOR_PAIR(2));
		mvwprintw(this->infa, 3, 65, "Lives: %d", this->health);
		wattroff(this->infa, COLOR_PAIR(2));
		mvwprintw(this->infa, 3, 35, "Time: %d", this->time);
		mvwprintw(this->infa, 5, 35, "Speed: %d", this->speed);
		mvwprintw(this->infa, 3, 145, "Overheat:");
		int red = 0;
		for (int i = 0; i < BULLETS; ++i)
			if (this->Ship.bullets[i].act)
				red++;
		wattron(this->infa, COLOR_PAIR(1));
		for (int i = 0; i < red; ++i)
			mvwaddch(this->infa, 5, 135 + i * 2, '!');
		wattroff(this->infa, COLOR_PAIR(1));
		wattron(this->infa, COLOR_PAIR(3));
		for (int i = 0; i < BULLETS - red; ++i)
			mvwaddch(this->infa, 5, 135 + (red + i) * 2, '!');
		wattroff(this->infa, COLOR_PAIR(3));
		if (!red)
			this->Ship.hot = false;
		if (this->Ship.hot) {
			wattron(this->infa, COLOR_PAIR(1));
			mvwprintw(this->infa, 3, 95, "YOUR WEAPON IS VERY HOT ! ! !");
			wattroff(this->infa, COLOR_PAIR(1));
			wattron(this->infa, COLOR_PAIR(2));
			if (red < BULLETS)
				mvwprintw(this->infa, 5, 95, "PRESS 'R' TO COOLDOWN ! ! ! !");
			wattroff(this->infa, COLOR_PAIR(2));
		}
		wattron(this->infa, COLOR_PAIR(1));
		if (this->enemy[0].exist)
			mvwprintw(this->infa, 5, 65, "Boss HP: %d", this->enemy[0].hp);
		wattroff(this->infa, COLOR_PAIR(1));
	} else if (this->lvlup) {
		wattron(this->win, COLOR_PAIR(3));
		mvwprintw(this->win, 24, 97, "Detail:");
		mvwprintw(this->win, 26, 78, "Lives: %d",  this->health);
		mvwprintw(this->win, 26, 111, "Score: %d", this->totalScore);
		mvwprintw(this->win, 28, 78, "Time: %d", this->time);
		mvwprintw(this->win, 28, 111, "Speed: %d", this->speed);
		wattroff(this->win, COLOR_PAIR(3));
		wattron(this->infa, COLOR_PAIR(2));
		wattron(this->win, COLOR_PAIR(2));
		if (this->level < FINAL) {
			mvwprintw(this->infa, 5, WIDTH / 2 - 6, "Next leve: %d", this->level + 1);
			mvwprintw(this->infa, 3, WIDTH / 2 - 16, "You got extra life for the boss!");
			mvwprintw(this->win, 18, WIDTH / 2 - 18, "Congratulations, you passed level: %d", this->level);
			mvwprintw(this->win, 21, WIDTH / 2 - 12, "Press \"F\" to continue.");
		} else {
			mvwprintw(this->infa, 3, WIDTH / 2 - 7, "YOU WON ! ! !");
			mvwprintw(this->win, 18, WIDTH / 2 - 13, "Congratulations, you won!");
			mvwprintw(this->win, 21, WIDTH / 2 - 12, "Press \"F\" for new game.");
		}
		wattroff(this->infa, COLOR_PAIR(2));
		wattroff(this->win, COLOR_PAIR(2));
	} else {
		wattron(this->infa, COLOR_PAIR(1));
		mvwprintw(this->infa, 3, WIDTH / 2 - 7, "You lose ! ! !");
		wattroff(this->infa, COLOR_PAIR(1));
		wattron(this->win, COLOR_PAIR(1));
		mvwprintw(this->win, 18, WIDTH / 2 - 5, "Game Over!");
		wattroff(this->win, COLOR_PAIR(1));
		wattron(this->win, COLOR_PAIR(2));
		mvwprintw(this->win, 21, WIDTH / 2 - 12, "Press \"F\" for new game.");
		wattroff(this->win, COLOR_PAIR(2));
		wattron(this->win, COLOR_PAIR(3));
		mvwprintw(this->win, 24, 95, "Last game:");
		mvwprintw(this->win, 26, 78, "Level: %d", this->level);
		mvwprintw(this->win, 26, 111, "Score: %d", this->totalScore);
		mvwprintw(this->win, 28, 78, "Time: %d", this->time);
		mvwprintw(this->win, 28, 111, "Speed: %d", this->speed);
		wattroff(this->win, COLOR_PAIR(3));
	}
	mvwprintw(this->infa, 7, WIDTH / 3, "Press:");
	mvwprintw(this->infa, 7, WIDTH / 3 + 10, (this->lvlup ? "f - continue" : "p - to pause"));
	mvwprintw(this->infa, 7, WIDTH / 3 + 27, "m - to turn on/off the sound");
	if (this->mus) {
		wattron(this->infa, COLOR_PAIR(2));
		mvwprintw(this->infa, 7, WIDTH / 3 + 50, "sound");
		wattroff(this->infa, COLOR_PAIR(2));
	}
	mvwprintw(this->infa, 7, WIDTH / 3 + 60, "ESC - to exit");
}

void	Window::my_clear() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			mvwaddch(this->win, i, j, ' ');
		}
	}
	for (int i = 0; i < SCORE_HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			mvwaddch(this->infa, i, j, ' ');
		}
	}
}

void	Window::set_mus(bool t) {
	if (this->mus)
		system("killall afplay");
	if (t)
		this->mus = (this->mus ? false : true);
	mvwprintw(this->infa, 7, WIDTH / 3 + 50, "sound");
	if (this->mus) {
		wattron(this->infa, COLOR_PAIR(2));
		mvwprintw(this->infa, 7, WIDTH / 3 + 50, "sound");
		wattroff(this->infa, COLOR_PAIR(2));
		if (!this->health)
			system("afplay ../sounds/loose.mp3 &");
		else if (this->level == FINAL && this->lvlup)
			system("afplay ../sounds/fin.mp3 &");
		else if (this->lvlup)
			system("afplay ../sounds/menu.mp3 &");
		else if (this->level == FINAL && this->enemy[0].exist)
			system("afplay ../sounds/finboss.mp3 &");
		else if (this->level == FINAL && !this->enemy[0].exist)
			system("afplay ../sounds/finlvl.mp3 &");
		else if (this->enemy[0].exist)
			system("afplay ../sounds/boss.mp3 &");
		else if (this->level == 1)
			system("afplay ../sounds/start.mp3 &");
		else
			system("afplay ../sounds/lvl.mp3 &");
	}
	wrefresh(this->infa);
}

int		Window::game_pause() {
	wattron(this->infa, COLOR_PAIR(2));
	mvwprintw(this->infa, 7, WIDTH / 3 + 17, "pause");
	wattroff(this->infa, COLOR_PAIR(2));
	wattron(this->win, COLOR_PAIR(6));
	mvwprintw(this->win, HEIGHT / 2 - 1, WIDTH / 2 - 3, "PAUSE");
	mvwprintw(this->win, HEIGHT / 2 + 1, WIDTH / 2 - 15, "Press 'p' or spase to continue");
	wattroff(this->win, COLOR_PAIR(6));
	wrefresh(this->win);
	int key = 0;
	wrefresh(this->infa);
	while (key != 'p' && key != ' ') {
		key = std::tolower(wgetch(this->win));
		if (key == 27)
			return 1;
		else if (key == 'm')
			set_mus(true);
	}
	return 0;
}

void	Window::start() {
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	wbkgd(this->frame, COLOR_PAIR(5));
	wrefresh(this->frame);
	wclear(this->win);
	system("afplay ../sounds/start.mp3 &");
	this->mus = true;
	while (1) {
		int key = std::tolower(wgetch(this->win));
		if (key == KEY_UP || key == 'w')
			this->Ship.moveShip(1);
		else if (key == KEY_DOWN || key == 's')
			this->Ship.moveShip(2);
		else if (key == KEY_LEFT || key == 'a')
			this->Ship.moveShip(3);
		else if (key == KEY_RIGHT || key == 'd')
			this->Ship.moveShip(0);
		else if (key == 'r') {
			if (this->Ship.hot)
				this->reloadGun();
		}
		else if (key == ' ') {
			if (!this->Ship.hot)
				this->Ship.createBullet();
		}
		else if (key == 27)
			break ;
		else if (key == '+')
			(this->speed > 249) && (this->speed -= 250);
		else if (key == '-')
			this->speed += 250;
		else if (key == 'f')
			this->newStart();
		else if (key == 'p') {
			if (!this->lvlup && this->health && this->game_pause())
				return;
		}
		else if (key == 'm')
			set_mus(true);
		
		if (this->health && !this->lvlup) {
			my_clear();
			wattron(this->win, COLOR_PAIR(4));
			for (int i = 0; i < STARS; i++)
				stars[i].actStars(this->win, !(this->time % 5));
			wattroff(this->win, COLOR_PAIR(4));

			if (this->enemy[0].exist < 2) {
				wattron(this->win, COLOR_PAIR(3));
				for (int i = 1; i < ASTEROIDS; i++)
					this->asteroid[i].actAsteroids(this->win, !(this->time % 3), this->enemy[0].exist);
				wattroff(this->win, COLOR_PAIR(3));
				wattron(this->win, COLOR_PAIR(1));
				this->enemyAttack();
				wattroff(this->win, COLOR_PAIR(1));
				if (!this->enemy[0].exist)
					this->accident();
			}
			clearBeggin();

			wattron(this->win, COLOR_PAIR(2));
			this->Ship.actShip(this->win);
			wattroff(this->win, COLOR_PAIR(2));
			if (!this->enemy[0].exist && this->score >= SCORE_TO_BOSS * this->level) {
				this->enemy[0].exist = 1;
				this->set_mus(false);
				for (int i = 0; i < ASTEROIDS; ++i) {
					if (this->asteroid[i].act == 1)
						this->asteroid[i].act = 2;
				}
				for (int i = 1; i < ENEMIES; ++i) {
					if (this->enemy[i].exist == 1)
						this->enemy[i].exist = 2;
				}
				for (int i = 0; i < MAX_BULLETS; ++i)
					this->enemyBullets[i].act = false;
			}
			if (this->enemy[0].exist) {
				wattron(this->win, COLOR_PAIR(1));
				this->enemy[0].printBoss(this->win);
				if (this->enemy[0].exist < 3) {
					if (!(this->time % 6))
						this->enemy[0].moveBoss();
					this->bulletsBoss();
					checkCrash();
				}
				wattroff(this->win, COLOR_PAIR(1));
				if (!(this->time % 42) && this->enemy[0].exist > 2) {
					if (this->enemy[0].exist++ > 5)
						this->lvlup = true;
				}
			}
			if (this->lvlup || !this->health) {
				wclear(this->win);
				wclear(this->infa);
				set_mus(false);
			}

			this->time++;

			Inform();
			wrefresh(this->win);
			wrefresh(this->infa);
		}

		usleep(this->speed);
	}
}

void	Window::newStart() {
	if (this->lvlup && this->level == FINAL)
		this->health = 0;
	if (this->health < 1) {
		this->level = 0;
		this->totalScore = 0;
		this->health = 2;
		this->lvlup = true;
		this->time = 0;
		this->Ship.x = 3;
		this->Ship.y = 24;
	}
	if (this->lvlup) {
		this->score = 0;
		this->speed = (SPEED - this->level * 900 < 1 ? 0 : SPEED - this->level * 900);
		this->totalScore += this->level * 100;
		this->health++;
		this->level++;
		this->enemy[0].hp = BOSS_HP * this->level;
		this->enemy[0].y = HEIGHT / 2 - 5;
		this->enemy[0].x = WIDTH;
		this->enemy[0].exist = 0;
		this->lvlup = false;
		this->set_mus(false);
		for (int i = 0; i < ASTEROIDS; ++i)
			this->asteroid[i].act = 0;
		for (int i = 0; i < BULLETS; ++i)
			this->Ship.bullets[i].act = false;
		for (int i = 1; i < ENEMIES; ++i) {
			this->enemy[i].x = 1 + (rand() % WIDTH - 2);
			this->enemy[i].y = 1 + rand() % (HEIGHT - 2);
			this->enemy[i].hp = 2;
			this->enemy[i].exist = 0;
		}
		for (int i = 0; i < MAX_BULLETS; ++i)
			this->enemyBullets[i].act = false;
	}
}

void	Window::reloadGun() {
	for (int i = 0; i < BULLETS; i++) {
		if (!this->Ship.bullets[i].act) {
			this->Ship.hot = false;
			return ;
		}
	}
}

void	Window::checkCrash() {
	for (int i = 0; i < BULLETS; ++i) {
		if (this->Ship.bullets[i].act && this->Ship.bullets[i].x < this->enemy[0].x + 4
			&& ((this->Ship.bullets[i].x > this->enemy[0].x - 6 && this->Ship.bullets[i].y
			> this->enemy[0].y + 2 && this->Ship.bullets[i].y < this->enemy[0].y + 6) ||
			(this->Ship.bullets[i].x > this->enemy[0].x - 4 && this->Ship.bullets[i].y
			> this->enemy[0].y - 1 && this->Ship.bullets[i].y < this->enemy[0].y + 9))) {
			this->Ship.bullets[i].act = false;
			this->enemy[0].hp--;
			if (this->enemy[0].hp < 1)
				this->enemy[0].exist = 3;
		}
		for (int j = 0; j < MAX_BULLETS; ++j) {
			if (this->enemyBullets[j].act && this->Ship.bullets[i].act && 
				this->Ship.bullets[i].y == enemyBullets[j].y && this->Ship.bullets[i].x > this->enemyBullets[j].x) {
				this->enemyBullets[j].act = false;
				this->Ship.bullets[i].act = false;
				mvwprintw(this->win, this->Ship.bullets[i].y - 1, this->Ship.bullets[i].x - 1, "\\  /");
				mvwprintw(this->win, this->Ship.bullets[i].y + 1, this->Ship.bullets[i].x - 1, "/  \\");
			}
		}
	}
}

void	Window::accident() {
	for (int i = 0; i < BULLETS; ++i) {
		for (int j = 0; j < ASTEROIDS; ++j) {
			if (this->asteroid[j].act == 1 && this->Ship.bullets[i].act &&
				this->Ship.bullets[i].y > this->asteroid[j].y - 2 && this->Ship.bullets[i].y
				< this->asteroid[j].y + 2 && this->Ship.bullets[i].x < this->asteroid[j].x
				+ 3 && this->Ship.bullets[i].x > this->asteroid[j].x - 1) {
				this->asteroid[j].act = 2;
				this->Ship.bullets[i].act = false;
				this->score++;
				this->totalScore++;
			}
		}
		for (int j = 0; j < MAX_BULLETS; ++j) {
			if (this->enemyBullets[j].act && this->Ship.bullets[i].act && 
				this->Ship.bullets[i].y == enemyBullets[j].y && this->Ship.bullets[i].x > this->enemyBullets[j].x) {
				this->enemyBullets[j].act = false;
				this->Ship.bullets[i].act = false;
				mvwprintw(this->win, this->Ship.bullets[i].y - 1, this->Ship.bullets[i].x - 1, "\\  /");
				mvwprintw(this->win, this->Ship.bullets[i].y + 1, this->Ship.bullets[i].x - 1, "/  \\");
			}
		}
		for (int j = 0; j < ENEMIES; ++j) {
			if (this->enemy[j].exist == 1 && this->Ship.bullets[i].y == enemy[j].y &&
				this->Ship.bullets[i].x > enemy[j].x && this->Ship.bullets[i].x < enemy[j].x + 4) {
				if (!(--this->enemy[j].hp))
					this->enemy[j].exist = 2;
					this->score += 5;
					this->totalScore += 5;
					this->Ship.bullets[i].act = false;					
			}
		}
	}
	for (int i = 0; i < ASTEROIDS; ++i) {
		if (this->asteroid[i].act == 1 && this->Ship.y > this->asteroid[i].y - 3
			&& this->Ship.y < this->asteroid[i].y + 3 && this->Ship.x <
			this->asteroid[i].x + 3 && this->Ship.x > this->asteroid[i].x - 3) {
			this->health--;
			this->asteroid[i].act = 2;
		}
	}
}

void	Window::bulletsBoss() {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (this->enemyBullets[i].act) {
			mvwprintw(this->win, this->enemyBullets[i].y, this->enemyBullets[i].x, "<<");
			if (this->enemyBullets[i].y < this->Ship.y + 2 && this->enemyBullets[i].y >
				this->Ship.y - 2 && this->enemyBullets[i].x > this->Ship.x - 1 &&
				this->enemyBullets[i].x < this->Ship.x + 3) {
				this->health--;
				this->enemyBullets[i].act = false;
			}
		}
		if (!this->enemyBullets[i].x--)
			this->enemyBullets[i].act = false;
	}
	if (!(this->time % 9)) {
		int i = MAX_BULLETS / 2;
		int r = (this->enemyBullets[i - 1].x < 1 ? 0 : i - 1);
		if (r && this->enemyBullets[0].x > 60)
			return ;
		while (i--) {
			if (!this->enemyBullets[r].act) {
				this->enemyBullets[r].act = true;
				this->enemyBullets[r].x = this->enemy[0].x - 6;
				this->enemyBullets[r].y = this->enemy[0].y + 4;
				return ;
			}
			r++;
		}
	}
}

void	Window::clearBeggin(void) {
	for (int i = 0; i < ASTEROIDS; ++i) {

		if (this->asteroid[i].act && this->asteroid[i].x > WIDTH - 5) {
			for (int j = 0; this->asteroid[i].x - j > WIDTH - 5; ++j) {
				mvwaddch(win, this->asteroid[i].y + 1, j, ' ');
				mvwaddch(win, this->asteroid[i].y + 2, j, ' ');
				mvwaddch(win, this->asteroid[i].y + 3, j, ' ');
				mvwaddch(win, this->asteroid[i].y, j, ' ');
				mvwaddch(win, this->asteroid[i].y - 1, j, ' ');
			}
		}
	}
}

void	Window::enemyAttack() {
	for (int i = 1; i < ENEMIES; ++i) {
		this->enemy[i].actEnemy(this->win, this->time);
		if (this->enemy[i].exist == 1) {
			int b = i * 2;
			if (this->Ship.y > this->enemy[i].y - 2	&& this->Ship.y <
				this->enemy[i].y + 2 && this->Ship.x < this->enemy[i].x + 3
				&& this->Ship.x > this->enemy[i].x - 3) {
				this->health--;
				this->enemy[i].exist = 2;
			} else if (!this->enemyBullets[b].act && !this->enemyBullets[b + 1].act &&
				this->enemyBullets[b + 1].x < enemy[i].x - 120) {
				this->enemyBullets[b].act = true;
				this->enemyBullets[b].x = enemy[i].x - 1;
				this->enemyBullets[b].y = enemy[i].y;
			} else if (!this->enemyBullets[b + 1].act && this->enemyBullets[b].x < enemy[i].x - 30) {
				this->enemyBullets[b + 1].act = true;
				this->enemyBullets[b + 1].x = enemy[i].x - 1;
				this->enemyBullets[b + 1].y = enemy[i].y;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (this->enemyBullets[i].act) {
			mvwprintw(this->win, this->enemyBullets[i].y, this->enemyBullets[i].x, "<-");
			if (this->enemyBullets[i].y < this->Ship.y + 2 && this->enemyBullets[i].y >
				this->Ship.y - 2 && this->enemyBullets[i].x > this->Ship.x - 1 &&
				this->enemyBullets[i].x < this->Ship.x + 3) {
				this->health--;
				this->enemyBullets[i].act = false;
			}
			if (!this->enemyBullets[i].x--)
				this->enemyBullets[i].act = false;
		}
	}
}

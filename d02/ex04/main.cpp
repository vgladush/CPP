/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:36:52 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/29 20:11:34 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	sort_res(std::string *s, int cn) {

	for (int i = 0; i < cn; ++i) {
		if (!s[i][0]) {
			int	j = i;
			while (j < cn &&  !s[j][0])
				j++;
			if (j == cn)
				return ;
			s[i] = s[j];
			s[j] = "";
		}
	}
}

void	eval_expr(std::string *s, int beg, int fin, int &cn) {

	if (s[beg][0] == '(') {
		s[beg][0] = 0;
		s[fin][0] = 0;
		fin -= 2;
		sort_res(s, cn);
		cn -= 2;
	}

	int ct = fin - beg;

	while (ct) {
		int	op = beg + 1;
		for (int i = beg + 1; i < fin; ++i) {
			if (s[i][0] == '*' || s[i][0] == '/') {
				op = i;
				break ;
			}
		}
		float	a = atof(s[op - 1].c_str()), b = atof(s[op + 1].c_str()), r = 0;
		s[op - 1] = "";
		if (s[op][0] == '*' || s[op][0] == '/')
			r = (s[op][0] == '*' ? a * b : a / b);
		else
			r = (s[op][0] == '+' ? a + b : a - b);
		Fixed	res(r);
		std::stringstream os;
		os << res.toFloat();
		os >> s[op - 1];
		s[op][0] = 0;
		s[op + 1][0] = 0;
		sort_res(s, cn);
		cn -= 2;
		ct -= 2;
		fin -= 2;
	}
}

void	find_scob(char *s) {

	int cn = 1;
	int	size = strlen(s);

	for (int i = 0; i < size; i++) {
		if (s[i] == ' ')
			cn++; 
	}

	std::string res[cn];

	int i = 0;
	while (*s) {
		if (*s == ' ')
			i++;
		else
			res[i] += *s;
		s++;
	}

	while (cn > 1) {
		int	sc = -1;
		int	sen = cn - 1;
		for (int i = 0; i < cn; i++) {
			if (res[i][0] == '(')
				sc = i;
		}
		if (sc > -1) {
			sen = sc;
			while (res[sen][0] != ')' && sen < cn)
				sen++;
		} else
			sc = 0;
		eval_expr(res, sc, sen, cn);
	}
	std::cout << res[0].c_str() << std::endl;
}

int		valid_arg(char *s) {
	int	sc = 0;
	if (*s != '(' && !isdigit(*s) && *s != '-' && !isdigit(*(s + 1)))
		return 1;
	while (*s) {
		if (*s == '(') {
			if (*(++s) != ' ')
				return 1;
			sc++;
			s++;
			if ((!isdigit(*s) && *s != '(' && *s != '-') || (*s == '-' && !isdigit(*(s + 1))))
				return 1;
		} else if (*s == ')' || isdigit(*s) || (*s == '-' && isdigit(*(s + 1)))) {
			if (*s == ')' && !sc--)
				return 1;
			if (*s == '-')
				s++;
			if (isdigit(*s)) {
				while (isdigit(*s))
					s++;
				if(*s == '.') {
					s++;
					while (isdigit(*s))
						s++;
				}
				s--;
			}
			s++;
			if (*s && *s++ != ' ')
				return 1;
			if (*s && *s != '+' && *s != '/' && *s != '*' && *s != ')'
				&& (*s != '-' || (*s == '-' && *(s + 1) != ' ')))
				return 1;
		} else if (*s == '+' || *s == '-' || *s == '*' || *s == '/') {
			if (*(++s) != ' ')
				return 1;
			s++;
			if ((!isdigit(*s) && *s != '(' && *s != '-') || (*s == '-' && !isdigit(*(s + 1))))
				return 1;
		} else
			return 1;
	}
	return (sc ? 1 : 0);
}

int		main(int ac, char **av) {

	if (ac != 2 || !strlen(av[1]) || valid_arg(av[1]))
		std::cout << "Bad usage! example: <<./eval_expr \"( 1 + 2 ) * 3 / ( ( 4 - 5 ) * 6 )\">>" << std::endl;
	else
		find_scob(av[1]);

	return 0;
}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/08 21:49:33 by vgladush          #+#    #+#              #
#    Updated: 2018/08/15 18:15:24 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	execute
CMPL	=	clang++
FLGS	=	-std=c++98 -Wall -Wextra -Werror
DIRC	=	./
FUNC	=	Form.cpp Bureaucrat.cpp RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp PresidentialPardonForm.cpp main.cpp
OBJC	=	$(FUNC:.cpp=.o)
OBJS	=	$(addprefix $(DIRC), $(OBJC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CMPL) -o $(NAME) $(OBJC)
	@echo "\x1B[0;32m$(NAME) ready\x1B[0m"

$(DIRC)%.o: $(DIRC)%.cpp
	@$(CMPL) $(FLGS) -o $@ -c $<

clean:
	@rm -f $(OBJC)
	@echo "\x1B[1;31mobjects $(NAME) deleted\x1B[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\x1B[1;31m$(NAME) deleted\x1B[0m"

re: fclean all

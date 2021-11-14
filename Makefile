# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 15:56:08 by jode-vri          #+#    #+#              #
#    Updated: 2021/11/14 15:56:11 by jode-vri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		pipex
CC				=		cc
FLAGS			=		-Wall -Werror -Wextra -g -I $(HEADER) #-fsanitize=address

HEADER          =		./inc/
SRCS            =		src/main.c			\
						src/utils.c			\
						src/ft_split.c		\
						src/utils2.c		\
						src/exec_pipe.c		

.c.o:
						@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

OBJS			=		$(SRCS:.c=.o)

all				:		$(NAME)

$(NAME)			:		$(OBJS) $(HEADER)
						@$(CC) -o $(NAME) $(FLAGS) $(OBJS)

clean			:
						rm -rf $(OBJS)

fclean			:		clean
						rm -f $(NAME)

re				:		fclean all
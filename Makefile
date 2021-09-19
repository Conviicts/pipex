# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 08:49:06 by admin             #+#    #+#              #
#    Updated: 2021/09/19 08:49:07 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		pipex
CC				=		gcc
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
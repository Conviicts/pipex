NAME			=		pipex
CC				=		gcc
FLAGS			=		-g -I $(HEADER) # -Wall -Werror -Wextra -fsanitize=address

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 17:27:32 by Ahussein          #+#    #+#              #
#    Updated: 2024/02/07 17:27:33 by Ahussein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = main.c parsing.c philo_actions.c philo_init.c monitor_death.c philo_routine.c
OBJS = $(SRC:.c=.o)
CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -lpthread ${CFLAGS} ${OBJS} -o $@


clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
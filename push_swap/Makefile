# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 20:49:50 by egorafanase       #+#    #+#              #
#    Updated: 2022/02/11 18:46:53 by pbomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ../libft/

RM = rm -f

HEADERS = pushswap.h

SOURCES = action_ps_v1.c action_ps_v2.c main_ps.c check_ps.c create_ps.c push_swap.c sort_ps.c

LIBFT_NAME = libft.a

LIBFT = $(addprefix ${LIBFTDIR}, ${LIBFT_NAME})

all:	${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}:	${SOURCES} ${HEADERS} ${LIBFT}
	${CC} ${CFLAGS} ${SOURCES} -L ${LIBFTDIR} -lft -o $@

clean:
	${MAKE} clean -C ${LIBFTDIR}

fclean:		clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re:	fclean all

.PHONY:	clean all fclean re
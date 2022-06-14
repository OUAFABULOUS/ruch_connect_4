# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 11:27:17 by ggiquiau          #+#    #+#              #
#    Updated: 2022/06/11 17:36:26 by ggiquiau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			= $(addprefix srcs/, get_next_line.c get_next_line_utils.c buf_write.c	\
					main.c)


OBJS            = ${SRCS:srcs%.c=${OBJS_DIR}%.o}
OBJS_DIR		= srcs/objs

LIBFTPATH		= libft/

HEADERS			= $(addprefix includes/, connect_four.h get_next_line.h) ${LIBFTPATH}libft.h

CC  			=  cc

ifdef TEST
CFLAGS		= -Wall -Wextra -g3 -Iincludes -Ilibft
else
CFLAGS			= -Wall -Wextra -Werror -Iincludes -Ilibft
endif

LFLAGS			= -L ${LIBFTPATH} -lft

NAME 			= connect4

RM 				= rm -f

${OBJS_DIR}/%.o:	srcs/*/%.c ${HEADERS}
					@mkdir -p ${OBJS_DIR}
					${CC} -c ${CFLAGS} -o $@ $<

${OBJS_DIR}/%.o:	srcs/*/*/%.c ${HEADERS}
					@mkdir -p ${OBJS_DIR}
					${CC} -c ${CFLAGS} -o $@ $<

${OBJS_DIR}/%.o:	srcs/%.c ${HEADERS}
					@mkdir -p ${OBJS_DIR}
					${CC} -c ${CFLAGS} -o $@ $<

all:			${NAME}

${NAME}:		${OBJS}
				@make bonus -C ${LIBFTPATH}
				${CC} ${OBJS} ${CFLAGS} ${LFLAGS} -o $@

test:
	@${MAKE} TEST=1
	@./${NAME} 6 7

debug:
	@${MAKE} TEST=1
	@valgrind --leak-check=full ./${NAME} 6 7

clean:
				@make $@ -C ${LIBFTPATH}
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:
				${RM} ${OBJS} ${OBJS_BONUS} ${NAME}
				@rm -fd ${OBJS_DIR} || true
				@make $@ -C ${LIBFTPATH}

re:
				${MAKE} fclean
				${MAKE} all

.PHONY:			all clean fclean re

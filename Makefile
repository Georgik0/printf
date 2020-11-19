# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skitsch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 15:16:18 by skitsch           #+#    #+#              #
#    Updated: 2020/11/14 15:18:11 by skitsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRCS = ft_printf.c get_flag.c get_width.c parser.c get_accuracy.c \
get_cpecifier.c get_type.c make_str_out/make_str_out.c \
make_str_out/make_str_c.c make_str_out/make_str_s.c \
make_str_out/make_str_p.c make_str_out/fill_space.c

OBJS = ${SRCS:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}

all:	${NAME}

test:	${OBJS}
		${GCC} -o ${NAME} *.o ./make_str_out/*.o -L ./libft -lft
		./${NAME}
# gcc -c *.c ./libft/ft_substr.c && ./a.out
# rm a.out
#${OBJS} test
#./test
#fclean

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

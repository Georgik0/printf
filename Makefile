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

NAME = libftprintf.a

NAME_LIBFT = libft.a

SRCS = ft_printf.c get_flag.c get_width.c parser.c get_accuracy.c \
get_cpecifier.c get_type.c make_str_out/make_str_out.c \
make_str_out/make_str_c.c make_str_out/make_str_s.c \
make_str_out/make_str_p.c make_str_out/fill_space.c \
make_str_out/make_str_d.c make_str_out/fill_zero.c \
make_str_out/get_size_d.c make_str_out/fill_space_d.c \
make_str_out/get_size_u.c make_str_out/make_str_u.c \
make_str_out/make_str_x.c make_str_out/make_str_percent.c \

OBJS = ${SRCS:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = libft/

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)libft.a ./
			mv $(NAME_LIBFT) $(NAME)
			ar -rc $(NAME) ${OBJS}

all:	${NAME}

test:	${OBJS}
		make -C $(LIBFT_DIR)
		${GCC} -o ${NAME} *.o ./make_str_out/*.o -L ./libft -lft
		./${NAME}
# make -C libft/
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

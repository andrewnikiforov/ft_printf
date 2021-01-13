# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omillan <omillan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 18:06:30 by omillan           #+#    #+#              #
#    Updated: 2020/12/30 14:31:44 by omillan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a
SRCE =		ft_itoa_base.c\
			ft_printf.c\
			func_parser.c\
			print_modif_arg_s_c_per.c\
			print_modif_arg.c\
			print_modif_arg_utils.c\
			print_modif_arg_utils_second.c\

HEADER =	ft_printf.h
OBJS = 		${SRCE:.c=.o}
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror -I ${HEADER}
AR =		ar rc
RM = 		rm -rf

all:		${NAME}

${NAME}:	${OBJS} libft/libft.a
			mv libft.a ${NAME}
			${AR} ${NAME} ${OBJS}

libft/libft.a:
			${MAKE}	-C ./libft/
			cp libft/libft.a ./
	
clean:
			${RM} ${OBJS}
			${MAKE} -C libft/ fclean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
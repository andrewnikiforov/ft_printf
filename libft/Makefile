# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omillan <omillan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:56:33 by omillan           #+#    #+#              #
#    Updated: 2020/12/25 19:23:52 by omillan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = 	ft_bzero.c\
		ft_memccpy.c\
	 	ft_memchr.c\
	  	ft_memcmp.c\
	   	ft_memcpy.c\
		ft_memset.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_memmove.c\
		ft_strchr.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strdup.c\
		ft_calloc.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strlcat.c\
		ft_atoi.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_split.c

BONUSSRCS = 	ft_lstnew.c\
				ft_lstdelone.c\
				ft_lstadd_back.c\
				ft_lstlast.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstmap.c\
				ft_lstiter.c\
				ft_lstsize.c\


HEADER 	= libft.h  
OBJS 	= ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRCS:.c=.o}
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I ${HEADER}
AR 		= ar rc
RM 		= rm -f

all:		${NAME}

$(NAME): 	${OBJS}
		 	${AR} ${NAME} ${OBJS}

bonus: 		${BONUSOBJS}
			${AR} ${NAME} ${BONUSOBJS}

clean: 
			${RM} ${OBJS} ${BONUSOBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re bonus

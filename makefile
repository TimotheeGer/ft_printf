# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 13:03:58 by tigerber          #+#    #+#              #
#    Updated: 2021/03/05 13:11:58 by tigerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c \
					conv_p.c \
					conv_x_maj.c \
					conv_pc.c \
					conv_s.c \
					conv_c.c \
     				outils_libft.c \
					outils_libft2.c \
					conv_d_i.c \
      				conv_u.c \
					outils_printf.c \
					conv_x.c 
															
SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

FOLDER			= srcs
HEADER			= includes

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}
				
$(NAME):		${OBJS}
				ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
clean:
				${RM} ${OBJS}
				
fclean:			clean
				${RM} ${NAME}

re:				fclean all
.PHONY: 		all fclean clean re

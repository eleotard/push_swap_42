# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 14:09:50 by eleotard          #+#    #+#              #
#    Updated: 2022/06/26 15:45:04 by eleotard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS =	main.c 			\
		ft_atoi_max.c 	\
		check_parsing.c \
		check_parsing2.c \
		list_utils.c \
		lst_moves.c \
		lst_moves_2.c \
		free_stuff.c \
		free_stuff2.c \
		mediane_stuff.c \
		sort.c 	\
		sort_utils.c \
		subsequence.c \
		subsequence_utils.c \
		sort_algo.c \
		sort_algo2.c \
		sort_algo3.c \

SRCS_BONUS =	checker_bonus.c		\
				checker_utils_bonus.c \
				ft_atoi_max.c 	\
				check_parsing.c \
				check_parsing2.c \
				list_utils.c \
				lst_moves_bonus.c \
				lst_moves_2_bonus.c \
				free_stuff.c \
				free_stuff2.c \
				sort_utils.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				subsequence_utils.c \
				
OBJS = ${SRCS:%.c=%.o}

OBJS_BONUS = ${SRCS_BONUS:%.c=%.o}

FLAGS =	-Wall -Wextra -Werror

CC = gcc

RM = rm -rf

LIBFT = -Llibft -lft 

PRINTF = -Lft_printf -lftprintf

%.o: %.c 
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} libft/libft.a ft_printf/libftprintf.a
	${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${PRINTF}

bonus: ${BONUS}

${BONUS}: ${OBJS_BONUS} libft/libft.a ft_printf/libftprintf.a
	${CC} ${FLAGS} -o ${BONUS} ${OBJS_BONUS} ${LIBFT} ${PRINTF}


ft_printf/libftprintf.a:
	make -C ft_printf

libft/libft.a:
	make -C libft bonus

clean:
	make -C libft clean
	make -C ft_printf clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	${RM} ${NAME} ${BONUS}

re: fclean all

.PHONY: all clean fclean re



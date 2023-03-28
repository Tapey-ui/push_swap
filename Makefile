# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 02:01:01 by nwai-kea          #+#    #+#              #
#    Updated: 2023/03/29 02:01:01 by nwai-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = array.c /
		count_rotation.c /
		error.c /
		index.c /
		init.c /
		one_arg.c /
		p_op.c /
		push_swap.c /
		r_op.c /
		return_a.c /
		return_to_a.c /
		rr_op.c /
		s_op.c /
		send_to_b.c /
		small_sort.c /
		sort_three.c /
		sort.c /
		utils.c /

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFT_PATH = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT_DIR)/$(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean: 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJS)

fclean: clean
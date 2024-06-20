# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 15:13:11 by jopfeiff          #+#    #+#              #
#    Updated: 2024/06/20 17:27:08 by jopfeiff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = free.c error_check.c push.c swap.c rotate.c reverse_rotate.c \
	node_init.c list_init.c ft_long_atoi.c push_swap.c find.c \
		sort/little_sort.c main.c utils/sorted.c
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes/
RM = rm -rf
NAME = libftpushswap.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	mkdir objs
	mv *.o ./objs && mv utils/*.o ./objs && mv sort/*.o ./objs
	cc libftpushswap.a -o push_swap
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) objs
	
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re

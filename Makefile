# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crystal <crystal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 15:13:11 by jopfeiff          #+#    #+#              #
#    Updated: 2024/07/24 10:33:02 by crystal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = error_free/free.c error_free/error_check.c moves/push.c moves/swap.c moves/rotate.c moves/reverse_rotate.c \
	node_init.c list_init.c utils/ft_long_atoi.c sort/push_swap.c find.c \
		sort/little_sort.c main.c utils/sorted.c sort/sorting.c \
			sort/turk_sort.c initialise_data.c moves/last_move.c \
				utils/len_list.c find_2.c
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes/
RM = rm -rf
NAME = libftpushswap.a
OBJS = $(SRCS:.c=.o)

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
MAGENTA= \033[35m
CYAN   = \033[36m
RESET  = \033[0m

.SILENT:

all: push_swap

push_swap: $(NAME) $(OBJS)
	echo "${CYAN}Compiling Push_Swap...${RESET}"
	cc libftpushswap.a -o push_swap
	echo "${GREEN}Succes!!!${RESET}"
$(NAME): $(OBJS)
	echo "${CYAN}Compiling libft...${RESET}"
	$(MAKE) --no-print-directory -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
clean:
	echo "${RED}Cleaning libft && Push_swap...${RESET}"
	$(MAKE) clean --no-print-directory -C ./libft
	$(RM) $(OBJS) objs
	echo "${GREEN}Succes!!!${RESET}"
	
fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	echo "${RED}Cleaning exucutable files...${RESET}"
	$(RM) $(NAME) push_swap
	echo "${GREEN}Succes!!!${RESET}"
re: fclean all

.PHONY: all clean fclean re

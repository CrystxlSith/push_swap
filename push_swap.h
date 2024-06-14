/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/14 10:55:04 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
typedef   struct s_node
{
	int	data;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

/* Gere un argument unique "-5 52 896 58" */
void	node_init(t_node **node, int nbr);
char	**ft_split(char const *s, char c);
void	list_init(t_node **head, char **argv, int flag);
void	free_prog(t_node *head, char **argv, int flag, int i);
void	free_argv(char **argv);
void	free_list(t_node *head);
long	ft_long_atoi(const char *nptr);
int	ft_reapeat(t_node *head, int nbr);
int	check_nbr(long nbr);
t_node	*find_last(t_node *node);
#endif
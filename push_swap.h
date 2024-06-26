/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/28 11:50:53 by jopfeiff         ###   ########.fr       */
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
	int	highest;
	int	med_plus;
	int all;
	int	lowest;
	int	median;
	int	count;
	int	total;
	int	index;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

/* Gere un argument unique "-5 52 896 58" */
void	node_init(t_node **node, int nbr);
void	print_list(t_node *head);
char	**ft_split(char const *s, char c);
int	list_init(t_node **head, char **argv, int flag);
int	sorted(t_node **a, t_node **b);
int	median(t_node **a);
void	free_prog(t_node *a, char **argv, int flag, int i);
void	sort_2(t_node **a);
void	free_argv(char **argv);
void	sorting(t_node **a, t_node **b, int count);
void	free_list(t_node *head);
long	ft_long_atoi(const char *nptr);
void	big_sort(t_node **a, t_node **b);
int	ft_reapeat(t_node *head, int nbr);
void	sort_4(t_node **a, t_node **b);
int	find_highest(t_node **a);
int	find_lowest(t_node **a);
int	check_nbr(long nbr);
void	sort_3(t_node **a);
t_node	*find_last(t_node *node);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	sa(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	pa(t_node **a, t_node **b);
void	little_sort(t_node **a, t_node **b, int count);
void	sort_2(t_node **a);
#endif
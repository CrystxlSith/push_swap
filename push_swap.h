/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/09 15:58:37 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
typedef   struct s_node
{
	int				data;
	int				highest;
	int				lowest;
	int				cost;
	int				index;
	bool			low_med;
	bool			lowest_price;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* Gere un argument unique "-5 52 896 58" */
void	node_init(t_node **node, int data);
void	print_list(t_node *head);
char	**ft_split(char const *s, char c);
char	**split_args(int argc, t_node *a, char *argv[]);
int	list_init(t_node **head, char **argv, int flag);
int	sorted(t_node **a, t_node **b);
int	count_char(int ac, char **av);
int	median(t_node **a);
int	check_char(char **argv, char *splitted, int flag);
t_node	*find_biggest_node(t_node *a);
t_node	*find_cheapest(t_node *a);
t_node	*find_lowest_node(t_node **list);
t_node	*find_max(t_node *node); //Define a function that searches a node and returns the node with the smallest number
t_node	*find_min(t_node *node); //Define a function that searches a node and returns the node with the smallest number
void	fill_node_a(t_node *a, t_node *b);
void	ft_up_min(t_node **a);
void 	free_prog(t_node *a, char **argv, int flag, int i);
void	fill_node_b(t_node *a, t_node *b);
void	sort_2(t_node **a);
void	ft_index(t_node *node);
void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	free_argv(char **argv);
void	sorting(t_node /* condition */**a, t_node **b, int count);
void	free_list(t_node *head);
long	ft_long_atoi(const char *nptr);
void	big_sort(t_node **a, t_node **b);
int	ft_reapeat(t_node *head, int data);
void	sort_4(t_node **a, t_node **b);
int	find_highest(t_node **a);
int	find_lowest(t_node **a);
int	len_list(t_node *lst);
int	check_data(long data);
void	sort_3(t_node **a);
t_node	*find_last(t_node *node);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	sa(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sb(t_node **b);
void	fill_node(t_node *a, t_node *b);
void	ss(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	pa(t_node **a, t_node **b);
void	little_sort(t_node **a, t_node **b, int count);
void	sort_2(t_node **a);
#endif
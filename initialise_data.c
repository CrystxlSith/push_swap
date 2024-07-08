/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:38 by crystal           #+#    #+#             */
/*   Updated: 2024/07/08 18:36:11 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	best_cost(t_node *a, t_node *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = len_list(a);
	len_stack_b = len_list(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->low_med))
			a->cost = len_stack_a - a->index;
		else if (a->target->low_med)
			a->cost += a->target->index;
		else
			a->cost += len_stack_b - a->target->index;
		a = a->next;
	}
	
}

static void	ft_target_a(t_node *a, t_node *b)
{
	t_node	*tmp_b;
	t_node	*target;
	long		best;

	while (a)
	{
		tmp_b = b;
		best = LONG_MIN;
		while (tmp_b)
		{
			if (tmp_b->data < a->data && tmp_b->data > best)
			{
				best = tmp_b->data;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (best == LONG_MIN)
			a->target = find_biggest_node(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	ft_target_b(t_node *a, t_node *b)
{
	t_node	*tmp_a;
	t_node	*target;
	long		best;

	while (b)
	{
		tmp_a = a;
		best = LONG_MAX;
		while (tmp_a)
		{
			if (tmp_a->data > b->data && tmp_a->data < best)
			{
				best = tmp_a->data;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (best == LONG_MAX)
			b->target = find_cheapest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	cheapest(t_node *a)
{
	long	cheapest;
	t_node	*cheapest_node;

	if (!a)
		return ;
	cheapest = LONG_MAX;
	while (a)
	{
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->lowest_price = true;
}

void	fill_node_a(t_node *a, t_node *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_a(a, b);
	best_cost(a, b);
	cheapest(a);
}

void	fill_node_b(t_node *a, t_node *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_b(a, b);
	
}
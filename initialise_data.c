/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:38 by crystal           #+#    #+#             */
/*   Updated: 2024/07/05 19:46:09 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	best_cost(t_node *a, t_node *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = ft_lstsize(a);
	len_stack_b = ft_lstsize(b);
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

static void	ft_target(t_node *a, t_node *b)
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

void	fill_node(t_node *a, t_node *b)
{
	ft_index(a);
	ft_index(b);
	ft_target(a, b);
	best_cost(a, b);
}
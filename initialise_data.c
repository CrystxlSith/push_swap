/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:38 by crystal           #+#    #+#             */
/*   Updated: 2024/07/05 16:07:16 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("a->data = %d, a->target->data = %d\n", a->data, a->target->data);
		a = a->next;
	}
}

void	fill_node(t_node *a, t_node *b)
{
	ft_index(a);
	ft_index(b);
	ft_target(a, b);
}
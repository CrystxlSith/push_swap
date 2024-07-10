/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:43:57 by crystal           #+#    #+#             */
/*   Updated: 2024/07/10 12:18:46 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*find_min(t_node *node)
{
	long	min;
	t_node	*min_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *node)
{
	long	max;
	t_node	*min_node;

	if (!node)
		return (NULL);
	max = LONG_MAX;
	while (node)
	{
		if (node->data < max)
		{
			max = node->data;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

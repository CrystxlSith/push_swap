/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:08:31 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/09 14:00:35 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_node *node)
{
	int	i;
	int	mid;

	if (!node)
		return ;
	mid = len_list(node) / 2;
	i = 0;
	while (node)
	{
		node->index = i;
		if (i <= mid)
			node->low_med = true;
		else
			node->low_med = false;
		node = node->next;
		i++;
	}
}

t_node	*find_biggest_node(t_node *a)
{
	t_node	*biggest;
	t_node	*cp;

	if (!a)
		return (NULL);
	cp = a;
	biggest = a;
	while (cp != NULL)
	{
		if (cp->data > biggest->data)
			biggest = cp;
		cp = cp->next;
	}
	return (biggest);
}

int	find_highest(t_node **a)
{
	int		high;
	t_node	*cp;

	cp = *a;
	high = (*a)->data;
	while (cp != NULL)
	{
		if (cp->data > high)
			high = cp->data;
		cp = cp->next;
	}
	return (high);
}

t_node	*find_cheapest(t_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->lowest_price == true)
			return (a);
		a = a->next;
	}
	return (NULL);
}

int	find_lowest(t_node **a)
{
	int		lowest;
	t_node	*cp;

	lowest = (*a)->data;
	cp = *a;
	while (cp != NULL)
	{
		if (cp->data < lowest)
			lowest = cp->data;
		cp = cp->next;
	}
	return (lowest);
}

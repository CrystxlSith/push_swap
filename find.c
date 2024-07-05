/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:08:31 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 14:23:02 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_node *node)
{
	int		i;
	int	mid;

	mid = len_list(node) / 2;
	i = 0;
	if(!node)
		return ;
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

int find_highest(t_node **a)
{
	int	high;
	t_node *cp;

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

int	find_lowest(t_node **a)
{
	int	lowest;
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
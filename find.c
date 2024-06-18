/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:08:31 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/18 18:18:56 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
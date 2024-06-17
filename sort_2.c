/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:49:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/17 18:23:19 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *find_highest(t_node **a)
{
	t_node *high;
	t_node *cp;

	cp = *a;
	high = *a;
	while (cp != NULL)
	{
		if (cp->data > high->data)
			high = cp;
		cp = cp->next;
	}
	return (high);
}

void	sort_3(t_node **a)
{
	t_node *highest;

	highest = find_highest(a);
	if ()
	
}

void	sort_2(t_node **a)
{
	if ((*a)->next->data < (*a)->data)
		sa(a);
}
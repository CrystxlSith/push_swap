/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:49:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/20 12:25:22 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_sort(t_node **a, t_node **b, int lowest, int highest)
{
	if ((*a)->next->data == lowest)
	{
		rra(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
	else if ((*a)->next->data == highest)
	{
		rra(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
		rra(a);
	}
}
void	sort_3(t_node **a)
{
	int	highest;

	highest = find_highest(a);
	if ((*a)->data > highest)
	{
		sa(a);
		if ((*a)->next->data > (*a)->next->next->data)
			ra(a);
	}
	else if ((*a)->next->data > highest)
	{
		rra(a);
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
		if ((*a)->next->data > (*a)->next->next->data)
			ra(a);
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
}


void	sort_4(t_node **a, t_node **b)
{
	int	highest;
	int	lowest;

	highest = find_highest(a);
	lowest = find_lowest(a);
	if ((*a)->data == highest)
	{
		pb(a, b);
		sort_3(a);
		pa(a, b);
		rra(a);
	}
	else if ((*a)->data == lowest)
	{
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
	else if ((*a)->next->data == lowest || (*a)->next->data == highest)
		last_sort(a, b, lowest, highest);
}	

void	sort_2(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
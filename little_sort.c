/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:49:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/18 18:30:38 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	
}	

void	sort_2(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
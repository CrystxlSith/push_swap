/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:49:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/20 18:12:46 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	last_sort(t_node **a, t_node **b, int lowest, int highest)
{
	if ((*a)->next->data == lowest)
	{
		sa(a);
		if (!sorted(a, b))
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
		}
	}
	else if ((*a)->next->data == highest)
	{
		sa(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
		ra(a);
	}
	else if ((*a)->next->next->data == lowest)
	{
		rra(a);
		if (!sorted(a, b))
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
			ra(a);
		}
	}
	else if ((*a)->next->next->data == highest)
	{
		rra(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
}
void	sort_3(t_node **a)
{
	int	highest;

	highest = find_highest(a);
	if ((*a)->data == highest)
	{
		if ((*a)->next->data > (*a)->next->next->data)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else if ((*a)->next->data == highest)
	{
			rra(a);
			if ((*a)->data > (*a)->next->data)
				sa(a);
	}
	else
	{
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
	if (!sorted(a, b))
	{
		if ((*a)->data == highest)
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
			ra(a);
		}
		else if ((*a)->data == lowest)
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
		}
		else
			last_sort(a, b, lowest, highest);
		
	}
}	

void	sort_2(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
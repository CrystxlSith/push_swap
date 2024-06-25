/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/25 07:45:10 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static t_node	*find_high(t_node **a)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp->next)
// 	{
// 		if (tmp->data == tmp->highest)
// 			break;
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }

static t_node	*find_low(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data == tmp->lowest)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

static void	updt_list(t_node **a)
{
	int	i;
	t_node *tmp;
	
	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->lowest = find_lowest(&tmp);
		tmp->highest = find_highest(&tmp);
		tmp->index = i; 
		tmp->median = (tmp->highest - tmp->lowest) / 2;
		tmp = tmp->next;
		i++;
	}
}

void	big_sort(t_node **a, t_node **b)
{
	t_node	*tmp;

	tmp = NULL;
	if (!a || !*a)
		return;
	if (!sorted(a, b))
	{
		while (*a)
		{
			updt_list(a);
			tmp = find_low(a);
			if (tmp->index > (*a)->median)
			{
				while ((*a) != tmp)
				{
					if ((*a)->next == NULL)
					{
						pb(a, b);
						break;
					}
					rra(a);
				}
			}
			else
			{
				while ((*a) != tmp)
				{
					if ((*a)->next == NULL)
					{
						pb(a, b);
						break;
					}
					ra(a);
				}
			}
			pb(a, b);
		}
		while (*b)
		{
			pa(a, b);
		}
   	 }
}
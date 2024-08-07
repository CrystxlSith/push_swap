/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:59 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/10 11:41:39 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_5(t_node **a, t_node **b, int count)
{
	int		j;
	int		min;

	j = 0;
	min = find_lowest(a);
	while (j < count || !sorted(a, b))
	{
		if ((*a)->data == min && !sorted(a, b))
		{
			pb(a, b);
			sort_4(a, b);
			break ;
		}
		else
			ra(a);
		j++;
	}
	sort_4(a, b);
	pa(a, b);
}

void	little_sort(t_node **a, t_node **b, int count)
{
	if (!*a || !(*a)->next)
		return ;
	if (count == 2)
		sort_2(a);
	if (count == 3)
		sort_3(a);
	if (count == 4)
		sort_4(a, b);
	if (count == 5)
		sort_5(a, b, count);
}

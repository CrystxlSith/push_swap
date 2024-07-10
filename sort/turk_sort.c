/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/10 11:38:27 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_lowest_node(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->data == tmp->lowest)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	push_cheapest(t_node **a, t_node *cheapest, char c)
{
	while (*a != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->low_med == true)
				ra(a);
			else
				rra(a);
		}
		else if (c == 'b')
		{
			if (cheapest->low_med == true)
				rb(a);
			else
				rrb(a);
		}
	}
}

void	to_a(t_node **a, t_node **b)
{
	push_cheapest(a, (*b)->target, 'a');
	pa(a, b);
}

void	to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->low_med == true && cheapest->target->low_med == true)
		rotate_both(a, b, cheapest);
	else if (cheapest->low_med == false && cheapest->target->low_med == false)
		reverse_rotate_both(a, b, cheapest);
	push_cheapest(a, cheapest, 'a');
	push_cheapest(b, cheapest->target, 'b');
	pb(a, b);
}

void	big_sort(t_node **a, t_node **b)
{
	int	a_len;

	a_len = len_list(*a);
	if (!a || !*a)
		return ;
	pb(a, b);
	pb(a, b);
	a_len -= 2;
	while (a_len-- > 3 && !sorted(a, b))
	{
		fill_node_a(*a, *b);
		to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		fill_node_b(*a, *b);
		to_a(a, b);
	}
	ft_index(*a);
	ft_up_min(a);
}

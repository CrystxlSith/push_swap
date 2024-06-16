/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:21:20 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/16 19:29:19 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	pb(t_node **a, t_node **b)
// {
// 	t_node *tmp;

// 	if (!*a)
// 		return ;
// 	tmp = *a;
// 	if (*a)
// 		(*a)->next = NULL;
// 	if (*b)
// 		(*b)->next = tmp;
// 	else
// 	{
// 		*b = tmp;
// 		(*b)->next = NULL;
// 	}
// 	ft_printf("pb\n");
// }

static void	push(t_node **dest, t_node **src)
{
	t_node	*new_node;

	if (!*src)
		return ;
	new_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new_node->prev = NULL;
	if (!*dest)
	{
		*dest = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dest;
		new_node->next->prev = NULL;
		*dest = new_node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
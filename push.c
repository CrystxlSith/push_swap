/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:21:20 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/14 14:59:37 by jopfeiff         ###   ########.fr       */
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

void pb(t_node **dest, t_node **src)
{
 	t_node	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
	ft_printf("pb\n");
}


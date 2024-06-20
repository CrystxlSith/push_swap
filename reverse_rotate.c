/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:11:47 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/20 11:59:57 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	reverse_rotate(t_node **ab)
// {
// 	t_node	*last;
// 	t_node	*before_last;

// 	last = *ab;
// 	before_last = NULL;
// 	if (!*ab || !(*ab)->next)
// 		return ;
// 	while (last->next)
// 		last = last->next;
// 	before_last = last->prev;
// 	before_last->next = NULL;
// 	last->prev = NULL;
// 	last->next = *ab;
// 	(*ab)->prev = last;
// 	*ab = last;
// }

static void reverse_rotate(t_node **ab)
{
	t_node *first;
	t_node *last;

	if (!*ab || !(*ab)->next)
		return;
	first = *ab;
	last = *ab;
	while (last->next)
		last = last->next;
	first->next->prev = NULL;
	*ab = first->next;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}


void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:32:53 by crystal           #+#    #+#             */
/*   Updated: 2024/06/25 14:21:53 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **ab)
{
	t_node	*first;
	t_node	*second;

	first = *ab;
	second = NULL;
	if (!*ab || !(*ab)->next)
		return ;
	second = first->next;
	second->prev = NULL;
	while (first->next)
		first = first->next;
	first->next = *ab;
	(*ab)->prev = first;
	(*ab)->next = NULL;
	*ab = second;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

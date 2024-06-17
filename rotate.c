/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:32:53 by crystal           #+#    #+#             */
/*   Updated: 2024/06/17 14:09:13 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **ab)
{
	t_node	*last;
	t_node	*tmp;

	if (!*ab || !(*ab)->next)
		return ;
	last = *ab;
	tmp = NULL;
	while (last->next)
		last = last->next;
	tmp = last->prev;
	tmp->next = NULL;
	last->next = *ab;
	*ab = last;
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

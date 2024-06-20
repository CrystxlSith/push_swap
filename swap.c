/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:01 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/20 15:53:21 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **a)
{
	// t_node	*tmp;

	// if (!*a || !(*a)->next)
	// 	return ;
	// tmp = *a;
	// *a = (*a)->next;
	// tmp->next = (*a)->next;
	// if ((*a)->next)
	// 	(*a)->next->prev = tmp;
	// (*a)->next = tmp;
	// tmp->prev = *a;
	// (*a)->prev = NULL;
	t_node	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *a;
	tmp->next = *a;
	tmp->prev = NULL;
	(*a)->prev = tmp;
	*a = tmp;
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

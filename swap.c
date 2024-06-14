/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:01 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/14 14:15:30 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **a)
{
 t_node	*tmp;

// 	// tmp = NULL;
// 	// if (!*a || !(*a)->next)
// 	// 	return ;
// 	// tmp->data = (*a)->data;
// 	// *a = (*a)->prev;
// 	// (*a)->next->data = (*a)->data;
// 	// (*a)->data = tmp->data;
// 	// *a = (*a)->next;
// 	// (*a)->next = NULL; 
// 	t_node	*tmp;
	
	tmp = NULL;
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;	
}

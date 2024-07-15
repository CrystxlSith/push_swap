/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:41:57 by crystal           #+#    #+#             */
/*   Updated: 2024/07/10 11:58:19 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_up_min(t_node **a)
{
	t_node	*tmp;

	tmp = find_min(*a);
	while ((*a)->data != tmp->data)
	{
		if (tmp->low_med)
			ra(a);
		else
			rra(a);
	}
}

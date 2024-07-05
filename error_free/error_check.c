/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:27:26 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 11:39:59 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	is_space(int c)
// {
// 	if (c == ' ')
// 		return (1);
// 	return (0);
// }

int	ft_reapeat(t_node *head, int nbr)
{
	while (head)
	{
		if (head->data == nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

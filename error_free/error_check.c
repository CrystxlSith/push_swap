/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:27:26 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/08 17:06:36 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	is_space(int c)
// {
// 	if (c == ' ')
// 		return (1);
// 	return (0);
// }

int	ft_reapeat(t_node *head, int data)
{
	while (head)
	{
		if (head->data == data)
			return (0);
		head = head->next;
	}
	return (1);
}

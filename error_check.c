/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:27:26 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/14 10:41:22 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nbr(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

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
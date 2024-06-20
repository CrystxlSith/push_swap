/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:59 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/18 18:14:35 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_sort(t_node **a, t_node **b, int count)
{
	if (!*a || !(*a)->next)
		return ;
	if (count == 2)
		sort_2(a);
	if (count == 3)
		sort_3(a);
	if (count == 4)
		sort_4(a, b);
}

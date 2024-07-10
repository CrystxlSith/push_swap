/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:21:57 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/09 16:36:00 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting(t_node **a, t_node **b, int count)
{
	if (count < 5)
		little_sort(a, b, count);
	else
	 	big_sort(a, b);
}
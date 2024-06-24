/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/24 15:21:59 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static t_node	*find_high(t_node **a)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp->next)
// 	{
// 		if (tmp->data == tmp->highest)
// 			break;
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }

static t_node	*find_low(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data == tmp->lowest)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

static void	updt_list(t_node **a)
{
	int	i;
	t_node *tmp;
	
	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->lowest = find_lowest(&tmp);
		tmp->highest = find_highest(&tmp);
		tmp->index = i; 
		tmp = tmp->next;
		i++;
	}
}

void	big_sort(t_node **a, t_node **b)
{
	int	i;
	t_node	*tmp;

	tmp = NULL;
	i = 0;
	if (!a || !*a) // Vérifier si la liste est vide
		return;
	if (!sorted(a, b)) // Vérifier si la liste est triée
	{
		while (*a)
		{
			// while (i != 1)
			// {
			// 	pb(a, b);
			// 	pb(a, b);
			// 	i++;
			// }
			// if ((*a)->data < (*a)->next->data)
			// 	sa(a);
			// if ((*b)->data > (*b)->next->data)
			// 	sb(b);
			// pb(a, b);
			// pb(a, b);
			updt_list(a);
			i = (*a)->lowest;
			tmp = find_low(a);
			if (tmp->index > (*a)->median)
			{
				while ((*a)->data != i)
				{
					ft_printf("tmp->index = %d\n", tmp->index);
					if ((*a)->next == NULL)
					{
						pb(a, b);
						break;
					}
					rb(a);
				}
			}
			else
			{
				while ((*a)->data != i)
				{
					ft_printf("tmp->index else = %d\n", tmp->index);
					//ft_printf("tmp->median = %d\n", tmp->median);
					if ((*a)->next == NULL)
					{
						pb(a, b);
						break;
					}
					ra(a);
				}
			}
			pb(a, b);
			// while (*a)
			// {
			// 	pb(a, b);
			// }
		}
		
		//if (sorted(a, b)) // Si la liste a est triée
			//break;
   	 }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/24 13:08:23 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    updt_lowest(t_node **a)
{
    t_node *tmp;
    tmp = *a;
    while (tmp)
    {
        tmp->lowest = find_lowest(&tmp);
        tmp = tmp->next;
    }
}

void	big_sort(t_node **a, t_node **b)
{
	t_node *line;
	if (!a || !*a) // Vérifier si la liste est vide
		return;
	line = NULL;
	if (!sorted(a, b)) // Vérifier si la liste est triée
	{
		while (*a)
		{
			// while ((*a)->data != (*a)->lowest) // Si le premier élément de la liste est le plus petit
			// {
			// 	ra(a); // On fait une rotation
			// }
			ra(a);
			if ((*a)->data <= (*a)->median)
			{
				pb(a, b);
			}
			//if ((*a)->data == (*a)->lowest) // Si le premier élément de la liste est le plus petit
				//pb(a, b); // On push le premier élément de la liste dans la liste b
			//updt_lowest(a); // On met à jour le plus petit élément de la liste a
			if (sorted(a, b)) // Si la liste a est triée
				break;
		}
		while (*b) // Tant que la liste b n'est pas vide
		{
			pa(a, b); // On push le premier élément de la liste b dans la liste a
		}
	
   	 }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/20 19:18:57 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_node **a, t_node **b)
{
    t_node *line;

    if (!a || !*a) // Vérifier si la liste est vide
        return;
    
    line = *a;

    while (!sorted(a, b))
    {
        if (!line->next) // Si nous atteignons la fin de la liste, recommencer depuis le début
        {
            line = *a;
            continue;
        }

        if (line->data > line->next->data)
        {
            sa(a); // Échanger les éléments
        }
        ra(a); // Effectuer une rotation
        line = *a; // Réinitialiser line après chaque rotation
    }
	// t_node *line;
	
	// line = *a;
	// while (!sorted(a, b))
	// {
	// 	if (line->data > line->next->data)
	// 		ra(a);
	// 	else
	// 	{
	// 		sa(a);
	// 		ra(a);		
	// 	}
	// }	
}
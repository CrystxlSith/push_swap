/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:49:02 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/13 14:19:31 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);	
}

void	node_init(t_node **node, int nbr)
{
	t_node	*new;
	t_node	*last;

	if (!node)
		return;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->data = nbr;
	if (*node == NULL)
	{
		*node = new;
		new->prev = NULL;
	}
	else
	{
		last = find_last(*node);
		last->next = new;
		new->prev = last;
	}
}
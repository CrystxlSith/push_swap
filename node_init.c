/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:49:02 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 14:46:28 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_params(t_node **new)
{
	(*new)->index = 0;
	(*new)->highest = 0;
	(*new)->lowest = 0;
	(*new)->median = 0;
}

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
		return ;
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
	init_params(node);
}

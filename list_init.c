/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:55 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/24 09:16:35 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	else_init(t_node **head)
{
	int	i;
	t_node *tmp;

	tmp = *head;
	i = 0;
	while ((*head)->next)
	{
		(*head)->index = i;
		(*head)->highest = find_highest(&tmp);
		(*head)->lowest = find_lowest(&tmp);
		(*head)->median = ((*head)->highest + (*head)->lowest) / 2;
		(*head) = (*head)->next;
		i++;
	}
	
}

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d -> ", current->data);
		current = current->next;
	}
	ft_printf("NULL\n");
}

int	list_init(t_node **head, char **argv, int flag)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (!flag)
	{	
		if (ft_strncmp(ft_strrchr(argv[0], '/'), "/push_swap", 7) == 0)
			i++;
	}
	while (argv[i])
	{
		nbr = ft_long_atoi(argv[i]);
		if (!check_nbr(nbr) || !ft_reapeat(*head, (int)nbr))
			free_prog(*head, argv, flag, 1);
		else
			node_init(head, (int)nbr);
		i++;
	}
	else_init(head);
	if (!flag)
		i -= 1;
	return (i);
}

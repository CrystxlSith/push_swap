/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:55 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 13:58:54 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!ft_reapeat(*head, (int)nbr) || nbr > INT_MAX || nbr < INT_MIN)
			free_prog(*head, argv, flag, 1);
		else
			node_init(head, (int)nbr);
		i++;
	}
	if (!flag)
		i -= 1;
	return (i);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:55 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/13 15:30:02 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_node *head)
{
    t_node *current = head;
    while (current != NULL)
    {
        ft_printf("%d -> ", current->data);
        current = current->next;
    }
    if (current->next == NULL)
    {
	while (current->prev != NULL)
	{
        	ft_printf("%d -> ", current->data);
        	current = current->prev;
	}
    }
    ft_printf("NULL\n");
}


void	list_init(t_node **head, char **argv, int flag)
{
	long	nbr;
	int	i;

	*head = NULL;
	i = 0;
	nbr = 0;
	if (!flag)
	{	
		if (ft_strncmp(ft_strrchr(argv[0], '/'), "/a.out", 7) == 0)
			i++;
	}
	while (argv[i])
	{
		nbr = ft_long_atoi(argv[i]);
		if (!check_nbr(nbr))
		{
			ft_printf("free\n");
			//free_list(head, argv);
		}
		if (!ft_reapeat(*head, (int)nbr))
		{
			ft_printf("free\n");
			//free_list(head, argv);
		}
		else
		{
			node_init(head, (int)nbr);
			print_list(*head);
		}
		i++;
	}
}

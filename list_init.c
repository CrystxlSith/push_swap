/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:55 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/12 14:15:31 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_init(t_node **head, char **argv)
{
	t_node	*new_node;
	long	nbr;
	int	i;

	new_node = NULL;
	*head = new_node;
	i = 0;
	nbr = 0;
	if (ft_strncmp(ft_strrchr(argv[0], '/'), "/a.out", 7) == 0)
		i++;
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
			node_init(&new_node, (int)nbr);
			ft_printf("SUCCESS\n");
		}
		i++;
	}
}

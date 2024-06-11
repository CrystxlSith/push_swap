/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:55 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/11 14:40:17 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_init(t_node **head, char **argv)
{
	long	nbr;
	int	i;

	i = 0;
	nbr = 0;

	while (argv[i])
	{
		nbr = ft_long_atoi(*argv);
		if (check_nbr(nbr) == 0)
			free_list(head, argv);
		if (repeat(head, nbr))
			free_list(head, argv);
		i++;;
	}
}
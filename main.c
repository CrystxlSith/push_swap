/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/11 15:16:23 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*tail;
	
	head = NULL;
	tail = NULL;
	int	i = 0;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	list_init(&head, argv);
	while (argv[i])
	{
		ft_printf("argv: %s\n", argv[i]);
		i++;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:36:16 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/17 14:58:39 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_prog(t_node *a, char **argv, int flag, int i)
{
	if (flag && a)
		free_argv(argv);
	free_list(a);
	if (i)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

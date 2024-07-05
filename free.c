/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:36:16 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 10:39:39 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(char **argv, char *splitted, int flag)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		if (!ft_isdigit(splitted[i]) && !ft_isspace(splitted[i]))
		{
			free(splitted);
			free_prog(NULL, argv, flag, 1);
		}
		i++;
	}
	return (1);
}

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
	if (flag)
		free_argv(argv);
	free_list(a);
	if (i)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

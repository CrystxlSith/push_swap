/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:27:26 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/10 14:45:51 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_args(int argc, t_node *a, char **argv)
{
	int		j;
	char	*splitted;

	j = 1;
	splitted = ft_calloc(sizeof(char), count_char(argc, argv) + 1);
	if (!splitted)
		return (NULL);
	else if (argc > 2)
	{
		while (argv[j])
		{
			splitted = ft_strjoin(splitted, argv[j]);
			if (!splitted)
				free_prog(a, argv, 1, 1);
			j++;
		}
		argv = ft_split(splitted, ' ');
		free(splitted);
	}
	return (argv);
}

int	ft_reapeat(t_node *head, int data)
{
	while (head)
	{
		if (head->data == data)
			return (0);
		head = head->next;
	}
	return (1);
}

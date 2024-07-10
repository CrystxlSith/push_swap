/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:27:26 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/09 15:54:30 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	is_space(int c)
// {
// 	if (c == ' ')
// 		return (1);
// 	return (0);
// }

char	**split_args(int argc, t_node *a, char **argv)
{
	int	j;
	char	*splitted;

	j = 1;
	splitted = ft_calloc(sizeof(char), count_char(argc, argv) + 1);
	if (!splitted)
		return (NULL);
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (free(splitted), NULL);
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
		check_char(argv, splitted, 1);
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

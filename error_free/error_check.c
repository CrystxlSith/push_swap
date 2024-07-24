/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:27:26 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/24 11:04:35 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_args(int argc, t_node *a, char **argv)
{
	int		j;
	int		i;
	char	*splitted;
	i = 0;
	j = 1;
	splitted = ft_calloc(sizeof(char), count_char(argc, argv) + 1);
	if (!splitted)
		return (NULL);
	while (argv[j])
	{
		ft_strlcat(splitted, argv[j], ft_strlen(splitted) + ft_strlen(argv[j]) + 1);
		if (!splitted)
			free_prog(a, argv, 1, 1);
		while (splitted[i])
			i++;
		splitted[i] = ' ';
		j++;
	}
	argv = ft_split(splitted, ' ');
	free(splitted);
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

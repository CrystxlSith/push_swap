/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/10 14:45:09 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_char(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	int		count;
	int		flag;
	char	**splitted;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		free_prog(a, argv, 0, 1);
	if (argc > 2)
		splitted = split_args(argc, a, argv);
	else if (argc == 2)
		splitted = ft_split(argv[1], ' ');
	if (!splitted)
		free_prog(a, splitted, 1, 1);
	flag = 1;
	count = list_init(&a, splitted, flag);
	if (!sorted(&a, &b))
		sorting(&a, &b, count);
	free_prog(a, splitted, flag, 0);
	return (0);
}

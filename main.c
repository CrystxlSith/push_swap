/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 10:40:47 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_char(int ac, char **av)
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

int main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	char	*splitted;
//	int	i;
int j = 1;
	int	count;
	int	flag;

	splitted = ft_calloc(sizeof(char), count_char(argc, argv) + 1);
	flag = 0;
	//i = 2;
	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2)
	{
		while (argv[j])
		{
			splitted = ft_strjoin(splitted, argv[j]);
			if (!splitted)
				free_prog(a, argv, 1, 1);
			j++;
		}
		ft_printf("splitted: %s\n", splitted);
		argv = ft_split(splitted, ' ');
		flag = 1;
	}
	check_char(argv, splitted, flag);
	free(splitted);
	count = list_init(&a, argv, flag);
	
	sorting(&a, &b, count);
	free_prog(a, argv, flag, 0);
	free_prog(b, argv, 0, 0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/02 13:23:55 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	char	*splitted;
//	int	i;
int j = 1;
	int	count;
	int	flag;

	splitted = ft_strdup("");
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
			splitted[ft_strlen(splitted)] = ' ';
			j++;
		}
		ft_printf("splitted: %s\n", splitted);
		argv = ft_split(splitted, ' ');
		flag = 1;
	}
	count = list_init(&a, argv, flag);
	sorting(&a, &b, count);
	free_prog(a, argv, flag, 0);
	free_prog(b, argv, flag, 0);
	return 0;
}

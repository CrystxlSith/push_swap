/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/20 15:46:39 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int	count;	
	int	flag;

	flag = 0;
	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		flag = 1;
	}
	count = list_init(&a, argv, flag);
	little_sort(&a, &b, count);
	//ft_printf("%d\n", count);
	//print_list(a);
	free_prog(a, argv, flag, 0);
	free_prog(b, argv, flag, 0);
	return 0;
}

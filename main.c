/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/14 22:55:22 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
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
	list_init(&a, argv, flag);
	print_list(a);
	sa(&a);
	print_list(a);
	sb(&b);
	print_list(a);
	ss(&a, &b);
	print_list(a);
	pb(&a, &b);
	print_list(a);
	print_list(b);
	pa(&b, &a);
	print_list(a);
	print_list(b);
	free_prog(b, argv, flag, 0);
	return 0;
}

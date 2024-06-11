/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/11 11:26:44 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	Node *tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	tail->data = 1;
	tail->prev = NULL;
	tail->next = malloc(sizeof(Node));
	if (!tail->next)
	{
		free(tail);
		ft_printf("Error\n");
		return (2);
	}
	tail->next->data = 2;
	tail->next->prev = tail;
	tail->next->next = malloc(sizeof(Node));
	if (!tail->next->next)
	{
		free(tail->next);
		free(tail);
		ft_printf("Error\n");
		return (3);
	}
	while (tail->next)
	{
		ft_printf("%d\n", tail->data);
		tail = tail->next;
	}
	// if (argc < 2)
	// {
	// 	ft_printf("Error\n");
	// 	return (1);
	// }
	// ft_printf(argv[1]);
	return 0;
}

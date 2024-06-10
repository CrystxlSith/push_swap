/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:00 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/10 15:53:39 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf(argv[1]);
	return 0;
}

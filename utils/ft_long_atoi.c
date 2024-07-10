/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:24 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/10 15:35:51 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || ft_isspace(str[i]))
	{
		i++;
		nb++;
	}
	if (str[i] || nb == 0 || nb > 10)
		return (0);
	return (1);
}

long	ft_long_atoi(const char *nptr, char **argv, t_node *a, int flag)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
			free_prog(a, argv, flag, 1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		free_prog(a, argv, flag, 1);
	return (result * sign);
}

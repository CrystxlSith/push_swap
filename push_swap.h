/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:05 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/11 14:27:21 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef   struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

/* Gere un argument unique "-5 52 896 58" */
static char	**split(char const *s, char c, char **res, size_t count);
void	list_init(t_node **head, char **argv);
long	ft_atoi(const char *nptr);

#endif
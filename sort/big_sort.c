/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/27 09:50:13 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// static	int	list_size(t_node **b)
// {
// 	t_node	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = *b;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (i);
// }

// static t_node	*find_lowest_list(t_node **a)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp->next)
// 	{
// 		if (tmp->data == tmp->lowest)
// 			break;
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }

// static int	is_low(t_node **a)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < tmp->median)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// static t_node	*find_low(t_node **a)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp->next)
// 	{
// 		if (tmp->data < tmp->median)
// 			break;
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }


static void	updt_list(t_node **a)
{
	t_node *tmp;
	t_node *tmp2;
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	tmp2 = *a;
	while (tmp2)
	{
		j ++;
		tmp2 = tmp2->next;	
	}
	tmp = *a;
	while (tmp)
	{
		tmp->lowest = find_lowest(&tmp);
		tmp->highest = find_highest(&tmp);
		tmp->index = i; 
		tmp->total = j;
		tmp->median = tmp->highest / 2;
		tmp = tmp->next;
		i++;
	}
}

static t_node	*find_high(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->data == tmp->highest)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}
// static void	sort_bef_med(t_node **a, t_node **b)
// {
// 	t_node	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = NULL;
// 	while (!sorted(b, NULL))
// 	{
// 		updt_list(b);
// 		tmp = find_low(b);
// 		if (tmp->index > tmp->total / 2)
// 		{
// 			while ((*b) != tmp)
// 			{
// 				if ((*b)->next == NULL)
// 				{
// 					pa(a, b);
// 					break;
// 				}
// 				rrb(a);
// 			}
// 		}
// 		else
// 		{
// 			while ((*a) != tmp)
// 			{
// 				if ((*a)->next == NULL)
// 				{
// 					pa(a, b);
// 					break;
// 				}
// 				rb(a);
// 			}
// 		}
// 		pb(a, b);
// 	}

// }

static int	rest2(t_node **a, int mid, int quart)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data < (quart + mid))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	rest(t_node **a, int quart)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data < quart)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
static void	check_sizes(t_node **a, t_node **b)
{
	if (!b || !*b)
		return;
	if (!a|| !*a)
		return;
	updt_list(b);
	updt_list(a);
	if ((*a)->data == (*a)->highest)
		ra(a);
	if ((*a)->next && (*b)->next)
	{
		if ((*b)->data < (*b)->next->data && (*a)->data > (*a)->next->data)
			ss(a, b);
	}
	if ((*a)->next != NULL)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	if ((*b)->next != NULL)
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
	}
}

static void	to_bb(t_node **a, t_node **b)
{
	int	mid;
	int	quart;
	updt_list(a);
	mid = (*a)->median;
	quart = mid / 2;
	while (rest2(a, mid, quart))
	{
		updt_list(a);
		check_sizes(a, b);
		if ((*a)->data < (mid + quart))
			pb(a, b);
		else
			ra(a);
	}
	while (*a)
	{
		check_sizes(a, b);
		pb(a, b);
	}
}


static void	to_b(t_node **a, t_node **b)
{
	int	mid;
	int	quart;
	
	updt_list(a);
	mid = (*a)->median;
	quart = mid / 2;
	while (rest(a, quart))
	{
		updt_list(a);
		check_sizes(a, b);
		if ((*a)->data < quart)
			pb(a, b);
		else
			ra(a);
	}
	while (rest(a, mid))
	{
		updt_list(a);
		check_sizes(a, b);
		if ((*a)->data < mid)
			pb(a, b);
		else
			ra(a);
	}
}

static void	to_a(t_node **a, t_node **b)
{
	t_node *tmp;

	tmp = NULL;
	while (*b)
	{
		updt_list(b);
		tmp = find_high(b);
		if (tmp->index > tmp->total / 2)
		{
			while ((*b) != tmp)
				rrb(b);
		}
		else
		{
			while ((*b) != tmp)
				rb(b);
		}
		pa(a, b);
	}
}

void	big_sort(t_node **a, t_node **b)
{
	if (!a || !*a)
		return;
	if (!sorted(a, b))
	{
		to_b(a, b);
		to_bb(a, b);
		to_a(a, b);
 	}
}
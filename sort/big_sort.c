/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/02 07:56:16 by jopfeiff         ###   ########.fr       */
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

static void	fill_arr(t_node **a, char *arr)
{
	t_node *tmp;
	int	i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	
}

static void	tab_sort(char *arr, int size)
{
    int i = 1;
    while (i < size)
	{
        int key = arr[i];
        int j = i - 1;

        // Déplace les éléments de arr[0..i-1] qui sont plus grands que key
        // d'une position vers la droite pour faire de la place pour key
        while (j >= 0 && arr[j] > key)
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        i++;
    }
}
int	list_size(t_node **lst)
{
	int	i;
	t_node *tmp;

	tmp = *lst;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	median(t_node **a)
{
	char *arr;
	int	i;

	i = list_size(a);
	arr = (char *)malloc(sizeof(char) * i);
	if (!arr)
		return (0);
	fill_arr(a, arr);
	tab_sort(arr, i);
	return (arr[i / 2]);
}

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
		tmp->median = median(a);
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

// static int	rest2(t_node **a, int mid, int quart)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < (quart + mid))
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

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
// static void	to_bb(t_node **a, t_node **b)
// {
// 	int	mid;
// 	int	total;
// 	int	quart;
// 	int	three_quarts;
	
// 	updt_list(a);
// 	mid = (*a)->median;
// 	total = mid * 2;
// 	quart = mid / 2;
// 	three_quarts = mid + quart;
// 	while (rest(a, mid))
// 	{
// 		updt_list(a);
// 		if ((*a)->data < quart)
// 		{
// 			pb(a, b);
// 			if (*b)
// 				rb(b);
// 		}
// 		else if ((*a)->data >= quart && (*a)->data < mid)
// 			pb(a, b);
// 		else
// 			ra(a);
// 	}
// 	while (*a)
// 	{
// 		updt_list(a);
// 		if ((*a)->data >= three_quarts)
// 		{
// 			pb(a, b);
// 		}	
// 		else if ((*a)->data < three_quarts)
// 		{
// 			pb(a, b);
// 			rb(b);
// 		}
// 		else
// 			ra(a);
// 	}
// }


static void	to_b(t_node **a, t_node **b)
{
	int	mid;
	int	quart;
	int	three_quarts;
	
	updt_list(a);
	mid = (*a)->median;
	quart = mid / 2;
	three_quarts = mid + quart;
	while (rest(a, mid))
	{
		updt_list(a);
		if ((*a)->next->next->next == NULL)
		{
			sort_3(a);
			break ;
		}
		if ((*a)->data < quart)
		{
			pb(a, b);
			if (*b)
				rb(b);
		}
		else if ((*a)->data >= quart && (*a)->data < mid)
			pb(a, b);
		else
			ra(a);
	}
	if ((*a)->next != NULL)
		to_b(a, b);
}
// 	while (*a)
// 	{
// 		updt_list(a);
// 		if ((*a)->data >= three_quarts)
// 		{
// 			pb(a, b);
// 		}	
// 		else if ((*a)->data < three_quarts)
// 		{
// 			pb(a, b);
// 			rb(b);
// 		}
// 		else
// 			ra(a);
// 	}
// }

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
		//to_bb(a, b);
		to_a(a, b);
 	}
}
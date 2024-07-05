/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/07/05 14:20:59 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len_list(t_node *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

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

int	median(t_node **a)
{
	char *arr;
	int	i;
	int	median;

	i = len_list(*a);
	arr = (char *)malloc(sizeof(char) * i);
	if (!arr)
		return (0);
	fill_arr(a, arr);
	tab_sort(arr, i);
	median = arr[i / 2];
	free(arr);
	return (median);
}

// static void	updt_list(t_node **a)
// {
// 	t_node *tmp;
// 	t_node *tmp2;
// 	int	i;
// 	int	j;
	
// 	j = 0;
// 	i = 0;
// 	tmp2 = *a;
// 	while (tmp2)
// 	{
// 		j ++;
// 		tmp2 = tmp2->next;	
// 	}
// 	tmp = *a;
// 	while (tmp)
// 	{
// 		tmp->lowest = find_lowest(&tmp);
// 		tmp->highest = find_highest(&tmp);
// 		tmp->index = i; 
// 		tmp->total = j;
// 		tmp->median = median(a);
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

// static t_node	*find_high(t_node **list)
// {
// 	t_node	*tmp;

// 	tmp = *list;
// 	while (tmp->next)
// 	{
// 		if (tmp->data == tmp->highest)
// 			break;
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }

// static int	rest(t_node **a, int quart)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < quart)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }


// static void	to_b(t_node **a, t_node **b)
// {
// 	int	mid;
// 	int	quart;
	
// 	updt_list(a);
// 	mid = (*a)->median;
// 	quart = mid / 2;
// 	while (rest(a, mid))
// 	{
// 		updt_list(a);
// 		if ((*a)->next->next->next == NULL)
// 		{
// 			sort_3(a);
// 			return ;
// 		}
// 		if ((*a)->data < quart)
// 		{
// 			pb(a, b);
// 			rb(b);
// 		}
// 		else if ((*a)->data >= quart && (*a)->data < mid)
// 			pb(a, b);
// 		else
// 			ra(a);
// 		to_b(a, b);
// 	}
// }

// static void	to_a(t_node **a, t_node **b)
// {
// 	t_node *tmp;

// 	tmp = NULL;
// 	if ((*a)->next->next->next != NULL)
// 	{
// 		if ((*a)->data == (*a)->highest)
// 			ra(a);
// 		while ((*a)->next)
// 			pb(a, b);
		
// 	}
// 	while (*b)
// 	{
// 		updt_list(b);
// 		tmp = find_high(b);
// 		if (tmp->index > tmp->total / 2)
// 		{
// 			while ((*b) != tmp)
// 				rrb(b);
// 		}
// 		else
// 		{
// 			while ((*b) != tmp)
// 				rb(b);
// 		}
// 		pa(a, b);
// 		if ((*a)->data > (*a)->next->data)
// 			sa(a);
// 	}
// }

void	big_sort(t_node **a, t_node **b)
{
	int	a_len;

	a_len = len_list(*a);
	if (!a || !*a)
		return;
	pb(a, b);
	pb(a, b);
	while (a_len-- > 3 && !sorted(a, b))
	{
		fill_node(*a, *b);
	}
	
}
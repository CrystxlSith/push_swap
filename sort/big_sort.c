/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/25 16:22:39 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// static	int	b_size(t_node **b)
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

static int	is_low(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data < tmp->median / 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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


static void	updt_list(t_node **a, int k)
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
		j++;
		tmp2 = tmp2->next;	
	}
	tmp = *a;
	while (tmp)
	{
		tmp->lowest = find_lowest(&tmp);
		tmp->highest = find_highest(&tmp);
		tmp->index = i; 
		tmp->total = j;
		tmp->median = tmp->highest / k;
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

static void	to_b(t_node **a, t_node **b)
{
	int	i;

	i = 2;
	while (is_low(a))
	{
		updt_list(a, i);
		if ((*a)->data < (*a)->median / 2 && (*a)->data > (*a)->median)
		{
			pb(a, b);
			rb(b);
		}
		if ((*a)->data < (*a)->median)
			pb(a, b);
		else
			ra(a);
	}
	while (!is_low(a))
	{
		updt_list(a, 2);
		if ((*a)->data == (*a)->highest)
			ra(a);
		if ((*a)->next == NULL)
			break ;
		if((*a)->data > (*a)->median)
			pb(a, b);
		else
			ra(a);
	}
}

// static void to_b(t_node **a, t_node **b) {
//     int segment_size = 2;

//     while (is_low(a)) {
//         updt_list(a, segment_size);
//         if ((*a)->data < (*a)->median) {
//             pb(a, b);
//         } else {
//             ra(a);
//         }
//     }

//     while (!is_low(a)) {
//         updt_list(a, segment_size);
//         if ((*a)->data == (*a)->highest) {
//             ra(a);
//         }
//         if ((*a)->next == NULL) {
//             break;
//         }
//         if ((*a)->data > (*a)->median) {
//             pb(a, b);
//         } else {
//             ra(a);
//         }
//     }

//     while (segment_size > 0) {
//         t_node *current = *a;
//         while (current != NULL) {
//             updt_list(a, segment_size);
//             if (current->data < (*a)->median) {
//                 pb(a, b);
//             } else {
//                 ra(a);
//             }
//             current = *a;
//         }
//         segment_size /= 2;
//     }
// }

static void	to_a(t_node **a, t_node **b)
{
	t_node *tmp;

	tmp = NULL;
	while (*b)
	{
		updt_list(b, 2);
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
	//t_node	*tmp;
	int		i;
	
	i = 10;
	//tmp = NULL;
	if (!a || !*a)
		return;
	if (!sorted(a, b))
	{
		to_b(a, b);
		to_a(a, b);
 	}
}
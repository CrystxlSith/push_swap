/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:23:38 by jopfeiff          #+#    #+#             */
/*   Updated: 2024/06/26 14:10:16 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static	int	get_size(t_node **b)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
// }

// static int	is_high(t_node **a, int i)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data > tmp->median / i)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// static int	is_low(t_node **a, int i)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < tmp->median / i)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

static void	updt_list(t_node **a, int k)
{
	t_node *tmp;
	t_node *tmp2;
	int	i;
	int	j;
	int	l;
	
	l = 0;
	j = 0;
	i = 0;
	tmp2 = *a;
	while (tmp2)
	{
		l += tmp2->data;
		j++;
		tmp2 = tmp2->next;	
	}
	tmp = *a;
	while (tmp)
	{
		tmp->lowest = find_lowest(&tmp);
		tmp->highest = find_highest(&tmp);
		tmp->index = i; 
		tmp->count = j;
		tmp->total = l;
		tmp->median = tmp->highest / k;
		tmp->med_plus = tmp->median + tmp->median / k;
		tmp = tmp->next;
		i++;
	}
}

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

// static void to_b(t_node **a, t_node **b) {
// 	int i = 10;
// 	while (i > 1) 
// 	{
// 		while (is_low(a, i)) {
// 			updt_list(a, i);
// 			if ((*a)->data < (*a)->median / i)
// 			{
// 				pb(a, b);
// 				rb(b);
// 			}
// 			if ((*a)->data < (*a)->median)
// 			{
// 				pb(a, b);
// 			}
// 			else 
// 			{
// 				ra(a);
// 			}
// 		}
// 		i--;
// 	}
	
// 	// while (!is_low(a, i))
// 	// {
// 	// 	updt_list(a, 2);
// 	// 	if ((*a)->data == (*a)->highest)
// 	// 	{
// 	// 		ra(a);
// 	// 	}
// 	// 	if ((*a)->next == NULL)
// 	// 	{
// 	// 		break;
// 	// 	}
// 	// 	if ((*a)->data > (*a)->median)
// 	// 	{
// 	// 		pb(a, b);
// 	// 	} else
// 	// 	{
// 	// 		ra(a);
// 	// 	}
// 	// }
// }

// static int	is_not_highest(t_node **a)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data!= tmp->highest && tmp->next != NULL)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }


// static int	med_check2(t_node **a, int i)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < tmp->med_plus / i)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// static int	med_check3(t_node **a, int i)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < tmp->median + tmp->median / i)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// static int	med_check(t_node **a, int i)
// {
// 	t_node	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->data < tmp->median / i)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// static void 	quick_sort(t_node **a, t_node **b)
// {
// 	int i = 10;
// 	if ((*a)->next != NULL)
// 	{
// 		while (i != 1) 
// 		{
// 			while (med_check(a, i)) {
// 				updt_list(a, i);
// 				if ((*a)->data < (*a)->med_plus / i)
// 				{
// 					pb(a, b);
// 					rb(b);
// 				}
// 				if ((*a)->data < (*a)->med_plus)
// 				{
// 					pb(a, b);
// 				}
// 				else 
// 				{
// 					ra(a);
// 				}
// 			}
// 			i--;
// 		}
// 		//quick_sort(a, b);
// 	}
// }
t_node *find_min(t_node *a) {
    t_node *min_node = a;
    while (a)
	{
        if (a->data < min_node->data)
		{
            min_node = a;
        }
        a = a->next;
    }
    return min_node;
}

// Fonction pour mettre à jour les indices
// void update_indices(t_node **a)
// {
//     t_node *tmp = *a;
//     int index = 0;
//     while (tmp)
// 	{
//         tmp->index = index++;
//         tmp = tmp->next;
//     }
// }

static int	is_quarter(t_node **a, int quarter, int i)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data < quarter * i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// Fonction de tri pour "push_swap"
void push_swap_sort(t_node **a, t_node **b)
{
	int size = get_size(a);
	int i = 1;
	updt_list(a, 2);
	int	quarter = (*a)->total / 4;
	ft_printf("quarter =%d\n", quarter);
	ft_printf("total =%d\n", (*a)->total);
	// while (i < 5 && size > 3)
	// {
	// 	while (is_quarter(a, quarter, i) == 1)
	// 	{
	// 		size = get_size(a);
	// 		quarter = (*a)->total / 4;
	// 		if ((*a)->data < quarter * i)
	// 		{
	// 			pb(a, b);
	// 		}
	// 		else
	// 		{
	// 			ra(a);
	// 		}
	// 	}
	// 	size--;
	// 	i++;
	// }
 	while (size > 3) {
        i = 1;
        while (i <= 4 && size > 3) {
            updt_list(a, 2); // Assurez-vous que cette fonction met correctement à jour 'total' et autres membres
            int quarter = (*a)->total / 4;
            while (is_quarter(a, quarter, i)) {
                if ((*a)->data < quarter * i) {
                    pb(a, b);
                    size = get_size(a); // Recalculez la taille après les opérations
                } else {
                    ra(a);
                }
            }
            i++;
        }
	}

	// Tri les 3 éléments restants dans la pile a
	if (!sorted(a, b))
	{
		sort_3(a);
	}

	// Renvoyer les éléments de b vers a
	while (*b)
	{
		pa(a, b);
	}
}

	// i = 10;
	// while (i != 1) 
	// {
	// 	while (is_high(a, i)) {
	// 		updt_list(a, i);
	// 		if ((*a)->data > (*a)->med_plus / i)
	// 		{
	// 			pb(a, b);
	// 			rb(b);
	// 		}
	// 		if ((*a)->data > (*a)->med_plus)
	// 		{
	// 			pb(a, b);
	// 		}
	// 		else 
	// 		{
	// 			ra(a);
	// 		}
	// 	}
	// 	i--;
	// }
void	big_sort(t_node **a, t_node **b)
{
	if (!a || !*a)
		return;
	if (!sorted(a, b))
	{
		push_swap_sort(a, b);
		// to_b(a, b);
		// to_a(a, b);
 	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 08:40:30 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/23 03:02:26 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_val(t_stack *a)
{
	int	min;

	if (!a)
		return (-1);
	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	sort_three(t_stack **a)
{
	t_stack	*head;
	int		max;

	if (!a || !*a || !(*a)->next)
		return ;
	head = *a;
	max = head->value;
	if (head->next->value > max)
		max = head->next->value;
	else if (head->next->next->value > max)
		max = head->next->next->value;
	if ((*a)->value == max)
		ra(a, 1);
	else if ((*a)->next->value == max)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;
	int	min;
	int	a_size;

	a_size = ft_lstsize(*a);
	while (a_size > 3)
	{
		min = get_min_index(*a);
		pos = get_pos(*a, min);
		if (pos <= a_size / 2)
		{
			while ((*a)->index != min)
				ra(a, 1);
		}
		else
		{
			while ((*a)->index != min)
				rra(a, 1);
		}
		pb(a, b, 1);
		a_size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}

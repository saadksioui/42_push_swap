/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:48:16 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 11:01:32 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	int	index;
	int	counter;

	counter = 0;
	while (*a)
	{
		index = (*a)->index;
		if (index <= counter)
		{
			pb(a, b, 1);
			rb(b, 1);
			counter++;
		}
		else if (index <= counter + chunk_size)
		{
			pb(a, b, 1);
			counter++;
		}
		else
			ra(a, 1);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	max_index;
	int	max_pos;

	while (*b)
	{
		max_index = get_max_index(*b);
		max_pos = get_pos(*b, max_index);
		size = ft_lstsize(*b);
		if (max_pos <= size / 2)
		{
			while ((*b)->index != max_index)
				rb(b, 1);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

void	chunk_sorting_algo(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = ft_lstsize(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	push_to_b(a, b, chunk_size);
	push_to_a(a, b);
}

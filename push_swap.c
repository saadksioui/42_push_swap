/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:48:16 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/20 09:34:40 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
}

void	push_to_a(t_stack **a, t_stack **b)
{
}
void	chunk_sorting_algo(t_stack **a, t_stack **b)
{
	int size;
	int chunk_size;

	size = ft_lstsize(*a);
	if (size <= 100)
		chunk_size = 10;
	else
		chunk_size = 30;
	push_to_b(*a, *b);
	push_to_a(*a, *b);
}
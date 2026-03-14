/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:25:06 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/23 04:22:33 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*move_b;

	if (!*b)
		return ;
	move_b = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	move_b->prev = NULL;
	if (!*a)
	{
		*a = move_b;
		move_b->next = NULL;
	}
	else
	{
		move_b->next = *a;
		(*a)->prev = move_b;
		*a = move_b;
	}
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*move_a;

	if (!*a)
		return ;
	move_a = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	move_a->prev = NULL;
	if (!*b)
	{
		*b = move_a;
		move_a->next = NULL;
	}
	else
	{
		move_a->next = *b;
		(*b)->prev = move_a;
		*b = move_a;
	}
	if (print)
		write(1, "pb\n", 3);
}

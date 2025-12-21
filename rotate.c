/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:25:01 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/15 11:31:09 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*r_a;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	r_a = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	r_a->next = NULL;
	r_a->prev = last;
	last->next = r_a;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	t_stack	*r_b;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	r_b = *b;
	last = ft_lstlast(*b);
	*b = (*b)->next;
	(*b)->prev = NULL;
	r_b->next = NULL;
	r_b->prev = last;
	last->next = r_b;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:22:59 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/20 09:39:21 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!*stack)
		return (0);
	curr = *stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(*a);
	else if (size <= 5)
		sort_five(*a, *b);
	else
		chunk_sorting_algo(*a, *b);
}

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1 || (argc == 2 && !argv[1]))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_init(&stack_a, argv, argc);
	sort_stack(&stack_a, &stack_b);
}
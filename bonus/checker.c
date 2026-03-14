/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:41:32 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 09:46:14 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
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
		return ;
	curr = *stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	ft_error_checker(t_stack **a, t_stack **b)
{
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
	ft_error();
}

void	checker(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "pa\n") == 0
		|| ft_strcmp(line, "pb\n") == 0)
		checker_s_p(a, b, line);
	else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0
		|| ft_strcmp(line, "rr\n") == 0 || ft_strcmp(line, "rra\n") == 0
		|| ft_strcmp(line, "rrb\n") == 0 || ft_strcmp(line, "rrr\n") == 0)
		checker_r(a, b, line);
	else
	{
		free(line);
		ft_error_checker(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
		ft_error();
	stack_a = NULL;
	stack_b = NULL;
	stack_init(&stack_a, argv, argc);
	index_stack(stack_a);
	line = get_next_line(0);
	while (line)
	{
		checker(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}

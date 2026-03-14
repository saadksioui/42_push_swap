/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:40:01 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 09:41:56 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_s_p(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 0);
}

void	checker_r(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0);
}

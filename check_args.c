/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:48:19 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 10:52:41 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str_n)
{
	int	i;

	if (!str_n || !str_n[0])
		return (0);
	i = 0;
	if (str_n[i] == '-' || str_n[i] == '+')
		i++;
	if (!str_n[i])
		return (0);
	while (str_n[i] != '\0')
	{
		if (!ft_isdigit(str_n[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_stack *a, int nbr)
{
	if (!a)
		return (1);
	while (a)
	{
		if (a->value == nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

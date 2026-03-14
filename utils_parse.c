/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 08:44:51 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/23 04:25:02 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *arg)
{
	long	nbr;
	int		i;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign *= -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		nbr = nbr * 10 + (arg[i] - '0');
		if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1))
			return (55555555555);
		i++;
	}
	return (nbr * sign);
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_and_free(t_stack **a, char **args)
{
	if (*a)
		free_stack(a);
	if (args)
		free_argv(args);
	ft_error();
}

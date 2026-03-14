/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:27 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 09:22:40 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_and_add(t_stack **a, char *str_nbr, char **argv)
{
	long	nbr;

	if (!check_syntax(str_nbr))
		ft_error_and_free(a, argv);
	nbr = ft_atol(str_nbr);
	if (nbr == 55555555555)
		ft_error_and_free(a, argv);
	if (!check_duplicate(*a, (int)nbr))
		ft_error_and_free(a, argv);
	ft_lstadd_back(a, ft_lstnew_dll((int)nbr));
}

void	stack_init(t_stack **a, char **argv, int argc)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			ft_error_and_free(a, NULL);
		if (!args[0])
			ft_error_and_free(a, args);
		j = 0;
		while (args[j])
		{
			parse_and_add(a, args[j], args);
			j++;
		}
		free_argv(args);
		i++;
	}
}

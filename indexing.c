/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 08:59:33 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/23 14:33:36 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(t_stack *a, int size)
{
	int	i;
	int	*arr;

	if (!a)
		return (NULL);
	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (a)
	{
		arr[i] = a->value;
		i++;
		a = a->next;
	}
	return (arr);
}

void	sort_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack *a)
{
	int	size;
	int	i;
	int	*tab;

	if (!a)
		return ;
	size = ft_lstsize(a);
	tab = fill_array(a, size);
	if (!tab)
		ft_error_and_free(&a, NULL);
	sort_array(tab, size);
	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == tab[i])
				a->index = i;
			i++;
		}
		a = a->next;
	}
	free(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:25:47 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/28 21:34:42 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_node *a, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != a->data)
		i++;
	return (i);
}

void	ft_index(t_node *a, int *arr)
{
	if (a->next == NULL)
	{
		a->index = ft_find_index(a, arr);
		ft_rewind(&a);
		return ;
	}
	a->index = ft_find_index(a, arr);
	a = a->next;
	ft_index(a, arr);
}

int	find_median(int a, int b)
{
	return (b + ((a - b) / 2));
}
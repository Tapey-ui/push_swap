/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:09:52 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/28 22:23:15 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// system("leaks -q push_swap");
void	ft_error(int i)
{
	write(1, "Error\n", 6);
	exit(i);
}

int	check_repeat(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}

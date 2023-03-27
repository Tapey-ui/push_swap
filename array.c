/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:25:11 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/20 16:29:29 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	mid;
	int	tmp;

	mid = arr[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (arr[j] < mid)
		{
			i++;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
		j++;
	}
	tmp = arr[left];
	arr[left] = arr[i];
	arr[i] = tmp;
	return (i);
}

void	quicksort_array(int	*arr, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right);
		quicksort_array(arr, left, pivot - 1);
		quicksort_array(arr, pivot + 1, right);
	}
}
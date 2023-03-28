/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:01:12 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:01:12 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_r(t_node *b, int next_sort, int count)
{
	if (!b)
		return (INT_MAX);
	if (b->index == next_sort)
		return (count);
	if (!b->next)
		return (INT_MAX);
	b = b->next;
	return ((count_r(b, next_sort, (count + 1))));
}

static int	count_rr(t_node *b, int next_sort, int count)
{
	if (!b)
		return (INT_MAX);
	if (b->index == next_sort)
		return (count);
	if (!b->prev)
		return (INT_MAX);
	b = b->prev;
	return ((count_rr(b, next_sort, (count + 1))));
}

int	choose_rotation(t_node *b, int limit)
{
	int	r;
	int	rr;

	r = count_r(b, limit, 0);
	while (b->next != NULL)
		b = b->next;
	rr = count_rr(b, limit, 0);
	if (rr < r)
		return (1);
	return (0);
}

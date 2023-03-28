/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:03:30 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:03:30 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_smaller(t_node *a, t_stack *ps)
{
	while (a != NULL)
	{
		if (a->index <= ps->a->mid)
			if (a->index >= ps->a->low)
				return (1);
		a = a->next;
	}
	return (0);
}

void	send_b(t_nodes *s, t_stack *ps)
{
	ft_pb(&s->a, &s->b);
	if (s->b->index > ps->b->high)
		ps->b->high = s->b->index;
	if (s->b->index < ps->b->low)
		ps->b->low = s->b->index;
}

void	init_values(t_nodes *s, t_stack *ps, int *size)
{
	*size = ft_lstsize2(s->a);
	ps->b->high = INT_MIN;
	ps->b->low = INT_MAX;
	ps->a->mid = find_median(ps->a->high, ps->a->low);
}

void	send_min(t_nodes *s, t_stack *ps, int size)
{
	int	rot;
	int	i;

	i = 0;
	rot = 0;
	while ((i < size) && (check_smaller(s->a, ps)))
	{
		if (s->a->index <= ps->a->mid)
			send_b(s, ps);
		else
		{
			ft_ra(&s->a);
			rot++;
		}
		i++;
	}
	if (ps->a->low)
	{
		i = 0;
		while (i < rot)
		{
			ft_rra(&s->a);
			i++;
		}
	}
}

void	send_to_b(t_nodes *s, t_stack *ps)
{
	int	size;

	init_values(s, ps, &size);
	if ((ps->a->high - ps->a->low) < 10)
	{
		while (s->a && s->a->index >= ps->a->low)
			send_b(s, ps);
	}
	else
		send_min(s, ps, size);
}

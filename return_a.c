/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:57:50 by marvin            #+#    #+#             */
/*   Updated: 2023/03/26 21:14:47 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_biggest_to_a(t_nodes *s, t_stack *ps)
{
	ft_pa(&s->a, &s->b);
	ps->b->high--;
	if (s->a->index == ps->a->low)
	{
		ft_ra(&s->a);
		ps->a->low++;
	}
}

void	send_smallest_to_a(t_nodes *s, t_stack *ps)
{
	ft_pa(&s->a, &s->b);
	ft_ra(&s->a);
	ps->a->low++;
	ps->b->low++;
}

void	init_b_value(t_nodes *s, t_stack *ps)
{
	t_node	*tmp;

	tmp = s->b;
	ps->b->high = INT_MIN;
	ps->b->low = INT_MAX;
	while (tmp)
	{
		if (tmp->index > ps->b->high)
			ps->b->high = tmp->index;
		if (tmp->index < ps->b->low)
			ps->b->low = tmp->index;
		tmp = tmp->next;
	}
	ps->b->mid = find_median(ps->b->high, ps->b->low);
}

void	complete_sort(t_nodes *s, t_stack *ps)
{
	int	size;

	size = ft_lstsize2(s->b);
	init_b_value(s, ps);
	if (size == 0)
	{
		order_a(s, ps);
		return ;
	}
	else if (size == 1)
		ft_pa(&s->a, &s->b);
	else if (s->b->index == ps->a->low)
		send_smallest_to_a(s, ps);
	else if (s->b->index == ps->b->high)
		send_biggest_to_a(s, ps);
	else if (choose_rotation(s->b, ps->a->low))
		ft_rrb(&s->b);
	else
		ft_rb(&s->b);
	complete_sort(s, ps);
}

void	start_sort(t_nodes *s, t_stack *ps)
{
	int size;

	size = ft_lstsize2(s->b);
	init_b_value(s, ps);
	if (size == 0)
		return ;
	if ((s->b->index > ps->b->mid) || (size == 1))
		ft_pa(&s->a, &s->b);
	else if (s->b->index == ps->a->low)
		send_smallest_to_a(s, ps);
	else if (choose_rotation(s->b, ps->a->low))
		ft_rrb(&s->b);
	else
		ft_rb(&s->b);
	start_sort(s, ps);
}
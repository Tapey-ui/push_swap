/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:03:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:03:46 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_num(t_node *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node->index);
}

void	order_a(t_nodes *s, t_stack *ps)
{
	if (s->a->index == 0)
		ft_ra(&s->a);
	while (((s->a->index + 1) == (s->a->next->index)) && ((s->a->index
				- 1) == last_num(s->a)))
		ft_ra(&s->a);
	if (((s->a->index - 1) == last_num(s->a)))
		ft_ra(&s->a);
	ps->a->low = last_num(s->a) + 1;
}

void	sort(t_nodes *s, t_stack *ps)
{
	if (ft_checksort(s->a) && stack_full(s->a, ps->total))
		return ;
	if (ft_lstsize2(s->a) <= 5)
		ft_small_sort(&(s->a), &(s->b));
	else
	{
		send_to_b(s, ps);
		return_to_a(s, ps, ps->b->high);
	}
	sort(s, ps);
}

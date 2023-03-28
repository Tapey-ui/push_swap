/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:03:06 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:03:06 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resend_b(t_nodes *s, t_stack *ps, int lim)
{
	while ((s->a->index <= lim) && (s->a->index >= ps->a->low))
		ft_pb(&s->a, &s->b);
}

void	return_to_a(t_nodes *s, t_stack *ps, int lim)
{
	int	size;

	size = ft_lstsize2(s->b);
	if (size < 50)
	{
		complete_sort(s, ps);
		return ;
	}
	start_sort(s, ps);
	resend_b(s, ps, lim);
	return_to_a(s, ps, lim);
}

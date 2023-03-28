/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:02:11 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:02:11 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	if (*a)
		(*a)->prev = tmp;
	tmp->next = *a;
	*a = tmp;
	(*a)->prev = NULL;
	write(1, "pa\n", 3);
}

void	ft_pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (*b)
		(*b)->prev = tmp;
	tmp->next = *b;
	*b = tmp;
	(*b)->prev = NULL;
	write(1, "pb\n", 3);
}

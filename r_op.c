/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:35:40 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/28 22:20:15 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

t_node	*add_last(t_node *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

void	push_up(t_node **node)
{
	t_node	*tmp;

	if (*node == NULL)
		return ;
	tmp = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = add_last(*node);
	tmp->prev->next = tmp;
}

void	ft_ra(t_node **a)
{
	push_up(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_node **b)
{
	push_up(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_node **a, t_node **b)
{
	push_up(a);
	push_up(b);
	write(1, "rr\n", 3);
}

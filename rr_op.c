/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:40 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/25 17:35:50 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_add_front(t_node **lst, t_node *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	push_down(t_node **node)
{
	t_node	*tmp;
	t_node	*last;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	ft_add_front(node, last);
}

void	ft_rra(t_node **a)
{
	push_down(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node **b)
{
	push_down(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **a, t_node **b)
{
	push_down(a);
	push_down(b);
	write(1, "rrr\n", 4);
}
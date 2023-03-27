/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:31:05 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/24 16:23:00 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort and pushes nodes until 3 nodes are left in stack

void	ft_sortb(t_node **a, t_node **b)
{
	if (ft_lstsize2(*a) == 3)
		return ;
	if ((*a)->data == ft_min(*a))
		ft_pb(a, b);
	else
	{
		if ((ft_lstlast2(*a)->data) == ft_min(*a))
			ft_rra(a);
		else
			ft_ra(a);
	}
	ft_sortb(a, b);
}

void	ft_push_a(t_node **a, t_node **b)
{
	if (!(*b))
		return ;
	if (ft_lstsize2(*b) > 1 && ((*b)->data < (*b)->next->data))
		ft_sb(b);
	ft_pa(a, b);
	ft_push_a(a, b);
}

void	ft_small_sort(t_node **a, t_node **b)
{
	if (ft_checksort(*a) && ft_lstsize2(*b) == 0)
		return ;
	if (ft_lstsize2(*a) == 2)
	{
		ft_sa(a);
		return ;
	}
	if (ft_lstsize2(*a) == 3)
	{
		ft_sort_three(a);
		ft_push_a(a, b);
	}
	else
		ft_sortb(a, b);
	ft_small_sort(a, b);
}

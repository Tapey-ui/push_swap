/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:03:41 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:03:41 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_node *a)
{
	int	i;

	i = a->data;
	while (a != NULL)
	{
		if (a->data < i)
			i = a->data;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_node *a)
{
	int	i;

	i = a->data;
	while (a != NULL)
	{
		if (a->data > i)
			i = a->data;
		a = a->next;
	}
	return (i);
}

void	ft_sort_three(t_node **a)
{
	if (ft_checksort(*a))
		return ;
	if (ft_min(*a) == (*a)->data && !(ft_checksort(*a)))
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (ft_max(*a) == (*a)->data && !(ft_checksort(*a)))
	{
		ft_ra(a);
		if (!ft_checksort(*a))
			ft_sa(a);
	}
	else
	{
		if (ft_min(*a) == (*a)->next->data)
			ft_sa(a);
		else
			ft_rra(a);
	}
}

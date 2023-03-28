/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:03:22 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:03:22 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

void	ft_swap(t_node **node)
{
	t_node	*tmp;
	t_node	*nexttmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	nexttmp = tmp->next;
	tmp->next = nexttmp->next;
	tmp->prev = nexttmp;
	if (nexttmp->next)
		nexttmp->next->prev = tmp;
	nexttmp->next = tmp;
	nexttmp->prev = NULL;
	*node = nexttmp;
}

void	ft_sa(t_node **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_node **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}

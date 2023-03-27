/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:52:19 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/26 20:16:20 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast2(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_lstfirst2(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

int	ft_lstsize2(t_node *lst)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_rewind(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	*a = tmp;
}

void	ft_lstclear2(t_node **a)
{
	t_node	*tmp;
	t_node	*nxt;

	tmp = *a;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	*a = NULL;
}

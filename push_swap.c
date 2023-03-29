/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:02:20 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 16:23:49 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	ft_checksort(t_node *a)
{
	int	tmp;

	tmp = a->data;
	while (a)
	{
		if (tmp > a->data)
			return (0);
		tmp = a->data;
		a = a->next;
	}
	return (1);
}

t_node	*ft_insert_a(int argc, char **argv, int i)
{
	t_node	*list;
	t_node	*tmp;
	int		n;

	list = NULL;
	while (i < argc)
	{
		n = ft_atoi2(argv[i]);
		tmp = ft_newlist(n);
		ft_add_behind(&list, tmp);
		i++;
	}
	return (list);
}

int	stack_full(t_node *a, int size)
{
	int	stack_size;

	stack_size = 0;
	while (a->next != NULL)
	{
		stack_size++;
		a = a->next;
	}
	stack_size++;
	if (stack_size == size)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_nodes	*s;
	t_stack	ps;

	s = NULL;
	s = ft_init_nodes(s);
	ft_init(s, &ps, argc, argv);
	sort(s, &ps);
	ft_lstclear2(&(s->a));
	ft_lstclear2(&(s->b));
	free(ps.arr);
	return (0);
}

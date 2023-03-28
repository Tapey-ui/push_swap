/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:09:40 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/28 22:12:52 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(t_node *a, int size, int i)
{
	int	*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		ft_error(1);
	while (i < size)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	if (check_repeat(arr, size))
		ft_error(1);
	quicksort_array(arr, 0, (size - 1));
	return (arr);
}

t_nodes	*ft_init_nodes(t_nodes *s)
{
	s = malloc(sizeof(t_nodes));
	s->a = NULL;
	s->b = NULL;
	return (s);
}

void	ft_init_stacks(t_stack *ps, int argc, int type)
{
	ps->a = malloc(sizeof(t_info));
	ps->b = malloc(sizeof(t_info));
	if (type == 0)
		ps->total = argc;
	else
		ps->total = argc - 1;
	ps->a->mid = 0;
	ps->b->mid = 0;
	ps->a->high = ps->total - 1;
	ps->b->high = INT_MIN;
	ps->b->low = INT_MAX;
	ps->a->low = 0;
	ps->arr = NULL;
}

t_node	*ft_newlist(int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_error(1);
	new->data = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_init(t_nodes *s, t_stack *ps, int argc, char **argv)
{
	if (argc < 2)
		ft_error(1);
	else if (argc == 2)
	{
		argc -= 2;
		argv = one_arg(&argc, argv);
		s->a = ft_insert_a(argc, argv, 0);
		ft_init_stacks(ps, argc, 0);
		ps->arr = fill_array(s->a, argc, 0);
		ft_index(s->a, ps->arr);
	}
	else
	{
		s->a = ft_insert_a(argc, argv, 1);
		ft_init_stacks(ps, argc, 1);
		ps->arr = fill_array(s->a, argc - 1, 0);
		ft_index(s->a, ps->arr);
	}
}

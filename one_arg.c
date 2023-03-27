/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:29:43 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/27 19:17:27 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

void	ft_add_behind(t_node **a, t_node *list)
{
	t_node	*last;

	if (list == NULL)
		return ;
	if (*a == NULL)
	{
		*a = list;
		return ;
	}
	last = ft_lstlast2(*a);
	last->next = list;
	list->prev = last;
}

void	ft_freelist(char **list)
{
	char	*n;

	while (*list)
	{
		n = *list;
		list++;
		free(n);
	}
	*list = NULL;
}

int	ft_atoi2(const char *str)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -sign;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(1);
		result = result * 10 + (*str++ - '0');
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error(1);
	return (result * sign);
}

char	**one_arg(int *argc, char **argv)
{
	t_node	*a;
	char	**tmp;
	int		i;

	i = 1;
	a = NULL;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
		i++;
	*argc = i;
	return (tmp);
}

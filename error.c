/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:09:52 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/21 19:10:04 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int i)
{
	write(1, "Error\n", 6);
	exit(i);
}

int		check_repeat(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}

// int	check_int(char **input, int i)
// {
// 	int	j;

// 	j = 0;
// 	if (input[i][j] == '-')
// 	{
// 		j++;
// 		if (!input[i][j])
// 			ft_error(1);
// 	}
// 	while (input[i][j])
// 	{
// 		if (!ft_isdigit(input[i][j]))
// 			ft_error(1);
// 		j++;
// 	}
// 	if (ft_atoi(input[i]) < INT_MIN || ft_atoi(input[i]) > INT_MAX)
// 		ft_error(1);
// }

// void	ft_isint(int argc, char **argv)
// {
// 	int		i;
// 	int		j;
// 	char	**tmp;

// 	i = 0;
// 	if (argc == 2)
// 	{
// 		if (check_int(argv, 1))
// 			ft_error(1);
// 	}
// 	else
// 	{
// 		while (++i < argc)
// 		{
// 			if (check_int(argv, i))
// 				ft_error(1);
// 		}
// 	}
// }
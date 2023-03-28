/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:02:27 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/03/29 02:02:27 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	long			data;
	struct s_node	*prev;
	struct s_node	*next;
	int				index;
}					t_node;

typedef struct s_nodes
{
	t_node			*a;
	t_node			*b;
}					t_nodes;

typedef struct s_info
{
	int				mid;
	int				high;
	int				low;
}					t_info;

typedef struct s_stack
{
	t_info			*a;
	t_info			*b;
	int				*arr;
	int				total;
}					t_stack;

t_nodes				*ft_init_nodes(t_nodes *s);
void				ft_init_stacks(t_stack *ps, int argc, int type);
void				ft_init(t_nodes *s, t_stack *ps, int argc, char **argv);
char				**one_arg(int *argc, char **argv);
t_node				*ft_newlist(int n);
t_node				*ft_lstlast2(t_node *lst);
void				ft_add_behind(t_node **a, t_node *list);
int					ft_atoi2(const char *str);
void				quicksort_array(int *arr, int left, int right);
int					*fill_array(t_node *a, int size, int i);
int					check_repeat(int *arr, int size);
t_node				*ft_insert_a(int argc, char **argv, int i);
int					ft_lstsize2(t_node *lst);
void				ft_index(t_node *a, int *arr);
int					stack_full(t_node *a, int size);
void				sorting(t_nodes *s, t_stack *ps);
void				ft_small_sort(t_node **a, t_node **b);
int					ft_min(t_node *a);
int					ft_max(t_node *a);
void				ft_sort_three(t_node **a);
int					ft_checksort(t_node *a);
void				ft_pa(t_node **a, t_node **b);
void				ft_pb(t_node **a, t_node **b);
void				ft_sa(t_node **a);
void				ft_sb(t_node **b);
void				ft_ss(t_node **a, t_node **b);
void				ft_rra(t_node **a);
void				ft_rrb(t_node **b);
void				ft_rrr(t_node **a, t_node **b);
void				ft_ra(t_node **a);
void				ft_rb(t_node **b);
void				ft_rr(t_node **a, t_node **b);
void				ft_rewind(t_node **a);
int					find_median(int a, int b);
int					choose_rotation(t_node *b, int limit);
void				send_to_b(t_nodes *s, t_stack *ps);
void				complete_sort(t_nodes *s, t_stack *ps);
void				start_sort(t_nodes *s, t_stack *ps);
void				order_a(t_nodes *s, t_stack *ps);
void				return_to_a(t_nodes *s, t_stack *ps, int lim);
void				sort(t_nodes *s, t_stack *ps);
void				ft_error(int i);
void				ft_lstclear2(t_node **a);

#endif
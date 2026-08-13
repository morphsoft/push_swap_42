/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 01:47:57 by joaopedr          #+#    #+#             */
/*   Updated: 2026/08/01 15:06:21 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "libft/libft.h"
# include "stack/stack.h"
# include "lexer/lexer.h"
# include "error_handling/error_handling.h"
# include "sorting_operations/sorting_operations.h"

typedef struct s_move
{
	int	pos_a;
	int	size_a;
	int	pos_b;
	int	size_b;
}	t_move;

# define LOG_MIN_CAP 64

typedef struct s_log
{
	char	*buf;
	size_t	len;
	size_t	cap;
	int		oom;
}	t_log;

typedef struct s_ops
{
	int		*count;
	t_log	*log;
}	t_ops;

typedef struct s_sort_run
{
	void			(*algo)(t_stack **stack, t_ops *ops);
	char			*label;
	unsigned char	flags;
	double			disorder;
}	t_sort_run;

void	run_sort(t_stack **stack_a, t_sort_run *run);
void	log_append(t_log *log, const char *op);

void	apply_swap(t_stack **stack, t_ops *ops);
void	apply_rotate(t_stack **stk, t_ops *ops);
void	apply_reverse_rotate(t_stack **stk, t_ops *ops);
void	apply_rotate_b(t_stack **stk, t_ops *ops);
void	apply_reverse_rotate_b(t_stack **stk, t_ops *ops);
void	apply_rotate_both(t_stack **a, t_stack **b, t_ops *ops);
void	apply_reverse_rotate_both(t_stack **a, t_stack **b, t_ops *ops);
void	apply_push(t_stack **stack_a, t_stack **stack_b, t_ops *ops);
void	apply_push_back(t_stack **stack_b, t_stack **stack_a, t_ops *ops);

int		move_cost(t_move *m);
int		min_pos(t_stack *stk, int size);
int		rank_pos(t_stack *stk, unsigned int rank, int size);
void	turn_to_top(t_stack **stk, int pos, int size, t_ops *ops);
void	turn_both(t_stack **a, t_stack **b, t_move *m, t_ops *ops);

void	sort_three(t_stack **stack_a, t_ops *ops);
void	selection_sort(t_stack **stack_a, t_ops *ops);

void	lis_sort(t_stack **stack_a, t_ops *ops);
int		*mark_lis(int *chain_len, int *prev_pos, int *ranks, int size);
void	push_non_lis(t_stack **a, t_stack **b, int *in_lis, t_ops *ops);
int		find_best(t_stack **a, t_stack **b);
void	insert_element(t_stack **a, t_stack **b, int best, t_ops *ops);

void	create_benchmark(unsigned char flags, char *class, int *op,
			double dis);

#endif

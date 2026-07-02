/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 01:47:57 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/23 15:51:05 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "libft/libft.h"
# include "stack/stack.h"
# include "vector_list/vector_list.h"
# include "lexer/lexer.h"
# include "error_handeling/error_handeling.h"
# include "sorting_operations/sorting_operations.h"

typedef struct s_ops
{
	int		*count;
	char	**log;
}	t_ops;

void	apply_swap(t_stack **stack, t_ops *ops);
void	apply_rotate(t_stack **stk, t_ops *ops);
void	apply_reverse_rotate(t_stack **stk, t_ops *ops);
void	apply_rotate_b(t_stack **stk, t_ops *ops);
void	apply_reverse_rotate_b(t_stack **stk, t_ops *ops);
void	apply_push(t_stack **stack_a, t_stack **stack_b, t_ops *ops);
void	apply_push_back(t_stack **stack_b, t_stack **stack_a, t_ops *ops);

void	sort_three(t_stack **stack_a, t_ops *ops);
void	selection_sort(t_stack **stack_a, t_ops *ops);
void	lis_sort(t_stack **stack_a, t_ops *ops);

void	push_non_lis(t_stack **a, t_stack **b, int *in_lis, t_ops *ops);
int		find_best(t_stack **a, t_stack **b);
void	insert_element(t_stack **a, t_stack **b, int best, t_ops *ops);

void	create_benchmark(char *name, int *op_count, char *ops, double dis);

#endif

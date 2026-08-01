/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:51:44 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:52:29 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	apply_rotate_b(t_stack **stk, t_ops *ops)
{
	char	*tmp;

	ft_rotate(stk, ROTATE_B);
	tmp = ft_strjoin(*ops->log, "rb\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[ROTATE_B] += 1;
}

void	apply_reverse_rotate_b(t_stack **stk, t_ops *ops)
{
	char	*tmp;

	ft_reverse_rotate(stk, REVERSE_ROTATE_B);
	tmp = ft_strjoin(*ops->log, "rrb\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[REVERSE_ROTATE_B] += 1;
}

void	apply_push(t_stack **stack_a, t_stack **stack_b, t_ops *ops)
{
	char			*tmp;
	int				value;
	unsigned int	rank;

	rank = (*stack_a)->rank;
	ft_pop(stack_a, &value);
	ft_push(stack_b, value, PUSH_B);
	(*stack_b)->rank = rank;
	tmp = ft_strjoin(*ops->log, "pb\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[PUSH_B] += 1;
}

void	apply_push_back(t_stack **stack_b, t_stack **stack_a, t_ops *ops)
{
	char			*tmp;
	int				value;
	unsigned int	rank;

	rank = (*stack_b)->rank;
	ft_pop(stack_b, &value);
	ft_push(stack_a, value, PUSH_A);
	(*stack_a)->rank = rank;
	tmp = ft_strjoin(*ops->log, "pa\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[PUSH_A] += 1;
}

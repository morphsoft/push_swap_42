/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:51:44 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:52:29 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	apply_swap(t_stack **stack, t_ops *ops)
{
	if ((*stack)->rank > (*stack)->next->rank)
	{
		ft_swap(stack, SWAP_A);
		log_append(ops->log, "sa\n");
		ops->count[SWAP_A] += 1;
	}
}

void	apply_rotate(t_stack **stk, t_ops *ops)
{
	ft_rotate(stk, ROTATE_A);
	log_append(ops->log, "ra\n");
	ops->count[ROTATE_A] += 1;
}

void	apply_reverse_rotate(t_stack **stk, t_ops *ops)
{
	ft_reverse_rotate(stk, REVERSE_ROTATE_A);
	log_append(ops->log, "rra\n");
	ops->count[REVERSE_ROTATE_A] += 1;
}

void	apply_rotate_both(t_stack **a, t_stack **b, t_ops *ops)
{
	ft_rotate_both(a, b, ROTATE_BOTH);
	log_append(ops->log, "rr\n");
	ops->count[ROTATE_BOTH] += 1;
}

void	apply_reverse_rotate_both(t_stack **a, t_stack **b, t_ops *ops)
{
	ft_reverse_rotate_both(a, b, REVERSE_ROTATE_BOTH);
	log_append(ops->log, "rrr\n");
	ops->count[REVERSE_ROTATE_BOTH] += 1;
}

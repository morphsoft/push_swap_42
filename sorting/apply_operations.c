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
	char	*tmp;

	if ((*stack)->rank > (*stack)->next->rank)
	{
		ft_swap(stack, SWAP_A);
		tmp = ft_strjoin(*ops->log, "sa\n");
		free(*ops->log);
		*ops->log = tmp;
		ops->count[SWAP_A] += 1;
	}
}

void	apply_rotate(t_stack **stk, t_ops *ops)
{
	char	*tmp;

	ft_rotate(stk, ROTATE_A);
	tmp = ft_strjoin(*ops->log, "ra\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[ROTATE_A] += 1;
}

void	apply_reverse_rotate(t_stack **stk, t_ops *ops)
{
	char	*tmp;

	ft_reverse_rotate(stk, REVERSE_ROTATE_A);
	tmp = ft_strjoin(*ops->log, "rra\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[REVERSE_ROTATE_A] += 1;
}

void	apply_rotate_both(t_stack **a, t_stack **b, t_ops *ops)
{
	char	*tmp;

	ft_rotate_both(a, b, ROTATE_BOTH);
	tmp = ft_strjoin(*ops->log, "rr\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[ROTATE_BOTH] += 1;
}

void	apply_reverse_rotate_both(t_stack **a, t_stack **b, t_ops *ops)
{
	char	*tmp;

	ft_reverse_rotate_both(a, b, REVERSE_ROTATE_BOTH);
	tmp = ft_strjoin(*ops->log, "rrr\n");
	free(*ops->log);
	*ops->log = tmp;
	ops->count[REVERSE_ROTATE_BOTH] += 1;
}

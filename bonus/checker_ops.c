/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:40:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/07/20 11:40:00 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push_a(t_stack **a, t_stack **b)
{
	int	value;

	if (!*b)
		return ;
	ft_pop(b, &value);
	ft_push(a, value, PUSH_A);
}

static void	push_b(t_stack **a, t_stack **b)
{
	int	value;

	if (!*a)
		return ;
	ft_pop(a, &value);
	ft_push(b, value, PUSH_B);
}

static int	exec_swap_push(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		return (ft_swap(a, SWAP_A), 1);
	if (!ft_strncmp(line, "sb\n", 4))
		return (ft_swap(b, SWAP_B), 1);
	if (!ft_strncmp(line, "ss\n", 4))
		return (ft_swap_both(a, b, SWAP_BOTH), 1);
	if (!ft_strncmp(line, "pa\n", 4))
		return (push_a(a, b), 1);
	if (!ft_strncmp(line, "pb\n", 4))
		return (push_b(a, b), 1);
	return (0);
}

static int	exec_rotate(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 4))
		return (ft_rotate(a, ROTATE_A), 1);
	if (!ft_strncmp(line, "rb\n", 4))
		return (ft_rotate(b, ROTATE_B), 1);
	if (!ft_strncmp(line, "rr\n", 4))
		return (ft_rotate_both(a, b, ROTATE_BOTH), 1);
	if (!ft_strncmp(line, "rra\n", 5))
		return (ft_reverse_rotate(a, REVERSE_ROTATE_A), 1);
	if (!ft_strncmp(line, "rrb\n", 5))
		return (ft_reverse_rotate(b, REVERSE_ROTATE_B), 1);
	if (!ft_strncmp(line, "rrr\n", 5))
		return (ft_reverse_rotate_both(a, b, REVERSE_ROTATE_BOTH), 1);
	return (0);
}

int	execute_op(t_stack **a, t_stack **b, char *line)
{
	if (exec_swap_push(a, b, line))
		return (1);
	if (exec_rotate(a, b, line))
		return (1);
	return (0);
}

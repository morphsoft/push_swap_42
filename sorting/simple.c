/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:55:51 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	simple_sort(t_stack **stack_a, unsigned char flags, double disorder)
{
	t_sort_run	run;

	run.algo = selection_sort;
	run.label = "O(n^2)";
	run.flags = flags;
	run.disorder = disorder;
	run_sort(stack_a, &run);
}

static void	rotate_min_to_top(t_stack **stack_a, t_ops *ops)
{
	int	size;

	size = ft_stack_size(*stack_a);
	turn_to_top(stack_a, min_pos(*stack_a, size), size, ops);
}

void	selection_sort(t_stack **stack_a, t_ops *ops)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_stack_size(*stack_a);
	while (size-- > 0)
	{
		rotate_min_to_top(stack_a, ops);
		apply_push(stack_a, &stack_b, ops);
	}
	while (stack_b)
		apply_push_back(&stack_b, stack_a, ops);
}

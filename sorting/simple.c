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
	int		op_count[11];
	char	*log;
	t_ops	ops;

	log = ft_strdup("");
	ft_bzero(op_count, sizeof(op_count));
	ops.count = op_count;
	ops.log = &log;
	selection_sort(stack_a, &ops);
	ft_printf("%s\n", log);
	if (flags & FLAG_BENCHMARK)
		create_benchmark(flags, "O(n^2)", op_count, disorder);
	free(log);
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

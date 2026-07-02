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
	if (flags & FLAG_BENCHMARK)
		create_benchmark("simple / 0(n2)", op_count, log, disorder);
	else
		ft_printf("%s\n", log);
	free(log);
}

static void	rotate_min_to_top(t_stack **stack_a, t_ops *ops)
{
	t_stack	*index;
	t_stack	*min_node;
	int		size;
	int		min_pos;
	int		i;

	index = *stack_a;
	min_node = *stack_a;
	size = ft_stack_size(*stack_a);
	i = 0;
	min_pos = 0;
	while (i < size)
	{
		if (index->rank < min_node->rank)
		{
			min_node = index;
			min_pos = i;
		}
		index = index->next;
		i++;
	}
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			apply_rotate(stack_a, ops);
	else
		while (min_pos++ < size)
			apply_reverse_rotate(stack_a, ops);
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

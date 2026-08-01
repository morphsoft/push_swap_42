/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	count_bits(unsigned int max_rank)
{
	int	bits;

	bits = 0;
	while (max_rank >> bits)
		bits++;
	return (bits);
}

static void	radix_sort(t_stack **stack_a, t_ops *ops)
{
	t_stack	*stack_b;
	int		size;
	int		bit;
	int		bits;
	int		i;

	stack_b = NULL;
	size = ft_stack_size(*stack_a);
	bits = count_bits((unsigned int)(size - 1));
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size && *stack_a)
		{
			if (((*stack_a)->rank >> bit) & 1)
				apply_rotate(stack_a, ops);
			else
				apply_push(stack_a, &stack_b, ops);
			i++;
		}
		while (stack_b)
			apply_push_back(&stack_b, stack_a, ops);
		bit++;
	}
}

void	complex_sort(t_stack **stack_a, unsigned char flags, double disorder)
{
	t_sort_run	run;

	run.algo = radix_sort;
	run.label = "O(n log n)";
	run.flags = flags;
	run.disorder = disorder;
	run_sort(stack_a, &run);
}

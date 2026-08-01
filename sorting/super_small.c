/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	push_smallest(t_stack **a, t_stack **b, t_ops *ops)
{
	int	size;

	size = ft_stack_size(*a);
	turn_to_top(a, min_pos(*a, size), size, ops);
	apply_push(a, b, ops);
}

static void	tiny_sort(t_stack **a, t_ops *ops)
{
	t_stack	*b;
	int		to_push;

	b = NULL;
	to_push = ft_stack_size(*a) - 3;
	while (to_push-- > 0)
		push_smallest(a, &b, ops);
	if (ft_stack_size(*a) == 3)
		sort_three(a, ops);
	else if (ft_stack_size(*a) == 2)
		apply_swap(a, ops);
	while (b)
		apply_push_back(&b, a, ops);
}

void	super_small_sort(t_stack **stack_a, unsigned char flags,
		double disorder)
{
	t_sort_run	run;

	run.algo = tiny_sort;
	run.label = "O(n^2)";
	run.flags = flags;
	run.disorder = disorder;
	run_sort(stack_a, &run);
}

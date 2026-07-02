/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 by hvaini-d                  #+#    #+#             */
/*   Updated: 2026/06/23 by hvaini-d                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	push_smallest(t_stack **a, t_stack **b, t_ops *ops)
{
	t_stack	*index;
	t_stack	*min;
	int		size;
	int		pos;
	int		i;

	index = *a;
	min = *a;
	size = ft_stack_size(*a);
	pos = 0;
	i = 0;
	while (i < size)
	{
		if (index->rank < min->rank)
		{
			min = index;
			pos = i;
		}
		index = index->next;
		i++;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			apply_rotate(a, ops);
	else
		while (pos++ < size)
			apply_reverse_rotate(a, ops);
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

void	super_small_sort(t_stack **stack_a, unsigned char flags, double disorder)
{
	int		op_count[11];
	char	*log;
	t_ops	ops;

	log = ft_strdup("");
	ft_bzero(op_count, sizeof(op_count));
	ops.count = op_count;
	ops.log = &log;
	tiny_sort(stack_a, &ops);
	if (flags & FLAG_BENCHMARK)
		create_benchmark("super_small / n<=5", op_count, log, disorder);
	else
		ft_printf("%s\n", log);
	free(log);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 by hvaini-d                  #+#    #+#             */
/*   Updated: 2026/06/23 by hvaini-d                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	try_push(t_stack **a, t_stack **b, t_chunk c, t_ops *ops)
{
	unsigned int	mid;

	if ((*a)->rank < c.min || (*a)->rank >= c.max)
		return (0);
	mid = (c.min + c.max) / 2;
	apply_push(a, b, ops);
	if ((*b)->rank < mid)
		apply_rotate_b(b, ops);
	return (1);
}

static void	push_chunk(t_stack **a, t_stack **b, t_chunk c, t_ops *ops)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_stack_size(*a);
	pushed = 0;
	while (pushed < (int)(c.max - c.min))
	{
		i = 0;
		while (i < size - pushed)
		{
			if (try_push(a, b, c, ops))
			{
				pushed++;
				break ;
			}
			apply_rotate(a, ops);
			i++;
		}
	}
}

static int	find_max_pos(t_stack *b, int size)
{
	t_stack			*index;
	unsigned int	max_rank;
	int				max_pos;
	int				i;

	index = b;
	max_rank = b->rank;
	max_pos = 0;
	i = 0;
	while (i < size)
	{
		if (index->rank > max_rank)
		{
			max_rank = index->rank;
			max_pos = i;
		}
		index = index->next;
		i++;
	}
	return (max_pos);
}

static void	pull_back(t_stack **b, t_stack **a, t_ops *ops)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = ft_stack_size(*b);
		max_pos = find_max_pos(*b, size);
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				apply_rotate_b(b, ops);
		else
			while (max_pos++ < size)
				apply_reverse_rotate_b(b, ops);
		apply_push_back(b, a, ops);
	}
}

static void	chunk_sort(t_stack **a, t_stack **b, int chunk_size, t_ops *ops)
{
	int		size;
	int		chunk;
	t_chunk	c;

	size = ft_stack_size(*a);
	chunk = 0;
	while (chunk * chunk_size < size)
	{
		c.min = chunk * chunk_size;
		c.max = (chunk + 1) * chunk_size;
		push_chunk(a, b, c, ops);
		chunk++;
	}
}

void	medium_sort(t_stack **stack_a, unsigned char flags, double disorder)
{
	t_stack	*stack_b;
	int		op_count[11];
	char	*log;
	t_ops	ops;
	int		chunk_size;

	stack_b = NULL;
	log = ft_strdup("");
	ops.count = op_count;
	ops.log = &log;
	chunk_size = ft_sqrt(ft_stack_size(*stack_a));
	if (chunk_size < 1)
		chunk_size = 1;
	chunk_sort(stack_a, &stack_b, chunk_size, &ops);
	pull_back(&stack_b, stack_a, &ops);
	if (flags & FLAG_BENCHMARK)
		create_benchmark("medium / O(n√n)", op_count, log, disorder);
	else
		ft_printf("%s\n", log);
	free(log);
}

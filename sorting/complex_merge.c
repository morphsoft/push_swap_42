/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 by hvaini-d                  #+#    #+#             */
/*   Updated: 2026/06/23 by hvaini-d                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	push_non_lis(t_stack **a, t_stack **b, int *in_lis, t_ops *ops)
{
	int	size;
	int	lis_count;
	int	min_lis_rank;
	int	i;

	size = ft_stack_size(*a);
	lis_count = 0;
	i = 0;
	while (i < size)
		lis_count += in_lis[i++];
	while (ft_stack_size(*a) > lis_count)
	{
		if (!in_lis[(*a)->rank])
			apply_push(a, b, ops);
		else
			apply_rotate(a, ops);
	}
	min_lis_rank = 0;
	while (!in_lis[min_lis_rank])
		min_lis_rank++;
	while ((*a)->rank != (unsigned int)min_lis_rank)
		apply_rotate(a, ops);
}

static int	find_insert_pos(t_stack *a, unsigned int rank, int size)
{
	t_stack	*node;
	int		i;

	node = a;
	i = 0;
	while (i < size)
	{
		if (node->rank < rank && node->next->rank > rank)
			return ((i + 1) % size);
		if (node->rank > node->next->rank)
			if (rank > node->rank || rank < node->next->rank)
				return ((i + 1) % size);
		node = node->next;
		i++;
	}
	return (0);
}

static int	element_cost(t_stack *a, t_stack *b_node, int pos_b, int size_b)
{
	int	size_a;
	int	pos_a;
	int	cost_a;
	int	cost_b;

	size_a = ft_stack_size(a);
	pos_a = find_insert_pos(a, b_node->rank, size_a);
	cost_a = (pos_a <= size_a / 2 ? pos_a : size_a - pos_a);
	cost_b = (pos_b <= size_b / 2 ? pos_b : size_b - pos_b);
	return (cost_a + cost_b);
}

int	find_best(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	int		size_b;
	int		best_pos;
	int		best_cost;
	int		i;

	node_b = *b;
	size_b = ft_stack_size(*b);
	best_pos = 0;
	best_cost = 2147483647;
	i = 0;
	while (i < size_b)
	{
		if (element_cost(*a, node_b, i, size_b) < best_cost)
		{
			best_cost = element_cost(*a, node_b, i, size_b);
			best_pos = i;
		}
		node_b = node_b->next;
		i++;
	}
	return (best_pos);
}

void	insert_element(t_stack **a, t_stack **b, int best, t_ops *ops)
{
	t_stack	*node;
	int		pos_a;
	int		size_a;
	int		size_b;
	int		i;

	node = *b;
	size_a = ft_stack_size(*a);
	size_b = ft_stack_size(*b);
	i = 0;
	while (i++ < best)
		node = node->next;
	pos_a = find_insert_pos(*a, node->rank, size_a);
	if (best <= size_b / 2)
		while (best-- > 0)
			apply_rotate_b(b, ops);
	else
		while (best++ < size_b)
			apply_reverse_rotate_b(b, ops);
	if (pos_a <= size_a / 2)
		while (pos_a-- > 0)
			apply_rotate(a, ops);
	else
		while (pos_a++ < size_a)
			apply_reverse_rotate(a, ops);
	apply_push_back(b, a, ops);
}

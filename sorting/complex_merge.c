/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by hvaini-d         ###   ########.fr       */
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
	size = ft_stack_size(*a);
	turn_to_top(a, rank_pos(*a, (unsigned int)min_lis_rank, size), size, ops);
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
	t_move	m;

	m.size_a = ft_stack_size(a);
	m.pos_a = find_insert_pos(a, b_node->rank, m.size_a);
	m.size_b = size_b;
	m.pos_b = pos_b;
	return (move_cost(&m));
}

int	find_best(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	int		size_b;
	int		best[2];
	int		cost;
	int		i;

	node_b = *b;
	size_b = ft_stack_size(*b);
	best[0] = 0;
	best[1] = 2147483647;
	i = 0;
	while (i < size_b)
	{
		cost = element_cost(*a, node_b, i, size_b);
		if (cost < best[1])
		{
			best[1] = cost;
			best[0] = i;
		}
		node_b = node_b->next;
		i++;
	}
	return (best[0]);
}

void	insert_element(t_stack **a, t_stack **b, int best, t_ops *ops)
{
	t_stack	*node;
	t_move	m;
	int		i;

	node = *b;
	i = 0;
	while (i++ < best)
		node = node->next;
	m.size_a = ft_stack_size(*a);
	m.size_b = ft_stack_size(*b);
	m.pos_a = find_insert_pos(*a, node->rank, m.size_a);
	m.pos_b = best;
	turn_both(a, b, &m, ops);
	apply_push_back(b, a, ops);
}
